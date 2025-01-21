/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 15:37:33 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/**
 * @brief Handles the state where the message is being received bit by bit.
 * 
 * In state 2, this function processes the received signal (SIGUSR1 or SIGUSR2) 
 * to set the corresponding bit in the message being constructed. Once the 
 * current character is fully received, it moves to the next character. If the 
 * entire message is received, it is printed, and the state transitions to 3.
 * 
 * @param current The current server data node for the client.
 * @param sig_received The signal received (SIGUSR1 or SIGUSR2).
 */
static void	handle_state_two(t_server_data *current, int sig_received)
{
	if (current->current_bit <= current->current_max_bits)
	{
		if (sig_received == SIGUSR1)
			current->message[current->current_char]
				|= (1 << (current->current_max_bits - current->current_bit));
		current->current_bit++;
		if (current->current_bit > current->current_max_bits)
		{
			current->current_bit = 0;
			current->current_char++;
			if ((size_t)current->current_char >= current->message_length)
			{
				ft_printf("%s", current->message);
				current->state = 3;
			}
		}
	}
}

/**
 * @brief Handles the state where the message length is being received.
 * 
 * In state 1, this function processes the received signal to construct 
 * the message length bit by bit. Once the full length is received, memory 
 * is allocated for the message, and the state transitions
 *  to 2 for message reception.
 * 
 * @param current The current server data node for the client.
 * @param sig The signal received (SIGUSR1 or SIGUSR2).
 */
static void	handle_state_one(t_server_data *current, int sig)
{
	if (current->current_bit <= current->current_max_bits)
	{
		if (sig == SIGUSR1)
			current->message_length |= (1 << (current->current_max_bits
						- current->current_bit));
		current->current_bit++;
		if (current->current_bit > current->current_max_bits)
		{
			if (current->message_length > 0)
			{
				current->message = malloc(current->message_length + 1);
				if (!current->message)
				{
					current->state = 3;
					return ;
				}
				ft_memset(current->message, 0, current->message_length);
				current->message[current->message_length] = '\0';
				current->current_bit = 0;
				current->current_max_bits = 7;
				current->state = 2;
			}
		}
	}
}

/**
 * @brief Initializes the transition from state 0 to state 1.
 * 
 * In state 0, this function prepares the server to receive
 *  the message length by 
 * setting the maximum bit count for the size of the message.
 * 
 * @param current The current server data node for the client.
 */
static void	handle_state_zero(t_server_data *current)
{
	current->state = 1;
	current->current_max_bits = sizeof(size_t) * 8 - 1;
}

/**
 * @brief Handles the server-side signal reception and processes the message.
 * 
 * This function is the signal handler for the server, responsible
 *  for managing
 * different states (0: waiting, 1: receiving length, 2: 
 * receiving message) for 
 * a client. Depending on the state, it delegates handling to
 *  `handle_state_zero`, 
 * `handle_state_one`, or `handle_state_two`. After processing
 *  the signal, it sends 
 * a response signal back to the client.
 * 
 * @param sig The signal received (SIGUSR1 or SIGUSR2).
 * @param info Information about the signal sender (client PID).
 * @param context Unused, passed as part of the signal handler signature.
 */
void	handle_signal_server(int sig, siginfo_t *info, void *context)
{
	t_server_data	*current;
	int				return_sig;

	(void)context;
	return_sig = SIGUSR1;
	current = find_node(info->si_pid);
	if (!current)
		return ;
	if (current->state == 0)
		handle_state_zero(current);
	else if (current->state == 1)
		handle_state_one(current, sig);
	else if (current->state == 2)
		handle_state_two(current, sig);
	else
		return_sig = SIGUSR2;
	kill(current->client_pid, return_sig);
	if (current->state == 3)
		free_node(current->client_pid);
}
