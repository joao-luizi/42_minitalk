/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signals_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/14 13:29:31 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk_bonus.h"

/**
 * @brief Handles the client state when the
 *  message has been successfully sent.
 * 
 * In state 3, this function prints a success
 *  message indicating that the server
 * has acknowledged the message, frees the 
 * allocated message, and exits the program.
 */
static	void	handle_state_three(void)
{
	ft_printf("Client %d: Server signals message \
	received sucessfully\nExiting...",
		getpid());
	exit(0);
}

/**
 * @brief Sends the message bit by bit to 
 * the server.
 * 
 * In state 2, this function sends each bit 
 * of the message character by character
 * to the server using SIGUSR1 (for 1) and 
 * SIGUSR2 (for 0). Once all characters
 * have been sent, the state is updated to 3.
 */
static	void	handle_state_two(void)
{
	unsigned char	byte_to_send;
	int				bit;

	if ((size_t)g_client_data.current_char < g_client_data.msg_len)
	{
		byte_to_send
			= (unsigned char)g_client_data.msg[g_client_data.current_char];
		if (g_client_data.current_bit <= g_client_data.current_max_bit)
		{
			bit = (byte_to_send >> (g_client_data.current_max_bit
						- g_client_data.current_bit)) & 1;
			if (bit)
				kill(g_client_data.server_pid, SIGUSR1);
			else
				kill(g_client_data.server_pid, SIGUSR2);
			g_client_data.current_bit++;
			if (g_client_data.current_bit > g_client_data.current_max_bit)
			{
				g_client_data.current_char++;
				g_client_data.current_bit = 0;
			}
		}
		if ((size_t)g_client_data.current_char == g_client_data.msg_len)
			g_client_data.state = 3;
	}
}

/**
 * @brief Sends the message length bit by bit
 *  to the server.
 * 
 * In state 1, this function sends the length 
 * of the message to the server
 * using SIGUSR1 (for 1) and SIGUSR2 (for 0). 
 * After all bits of the length are sent,
 * the state transitions to 2 for sending the 
 * actual message.
 */
static void	handle_state_one(void)
{
	int	bit;

	if (g_client_data.current_bit <= g_client_data.current_max_bit)
	{
		bit = (g_client_data.msg_len >> (g_client_data.current_max_bit
					- g_client_data.current_bit)) & 1;
		if (bit)
			kill(g_client_data.server_pid, SIGUSR1);
		else
			kill(g_client_data.server_pid, SIGUSR2);
		g_client_data.current_bit++;
		if (g_client_data.current_bit > g_client_data.current_max_bit)
		{
			g_client_data.current_bit = 0;
			g_client_data.current_max_bit = 7;
			g_client_data.state = 2;
		}
	}
}

/**
 * @brief Initializes the client to start sending
 *  the message length.
 * 
 * In state 0, this function sets up the client 
 * to send the length of the message 
 * by calculating the number of bits required and
 *  signaling the server to begin 
 * receiving the length.
 */
void	handle_state_zero_client(void)
{
	g_client_data.state = 1;
	g_client_data.current_max_bit = sizeof(size_t) * 8 - 1;
	g_client_data.msg_len = ft_strlen(g_client_data.msg);
	if (kill(g_client_data.server_pid, SIGUSR1) == -1)
		exit_error("Not server program", 2);
}

/**
 * @brief Handles incoming signals from the server
 *  and manages state transitions.
 * 
 * This function processes signals received from 
 * the server. If SIGUSR2 is received,
 * it indicates an error, and the client exits. 
 * Otherwise, based on the current state
 * (1: sending length, 2: sending message, 3: success)
 * , it delegates to the appropriate 
 * state handler (`handle_state_one`, `handle_state_two`
 * , or `handle_state_three`).
 * 
 * @param sig The signal received (SIGUSR1 or SIGUSR2).
 * @param info Information about the signal sender (unused).
 * @param context Unused, passed as part of the signal 
 * handler signature.
 */
void	handle_signal_client(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR2)
	{
		free(g_client_data.msg);
		exit_error("Received abnormal termination\
			from server\n Exiting...\n", 2);
	}
	else
	{
		if (g_client_data.state == 1)
			handle_state_one();
		else if (g_client_data.state == 2)
			handle_state_two();
		else if (g_client_data.state == 3)
			handle_state_three();
	}
}
