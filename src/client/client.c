/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:26:10 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/10 12:16:50 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

t_client_data	g_client_data;

/**
 * @brief Initializes the global client data 
 * struct with the server PID and message.
 * 
 * This function sets the client's initial 
 * state (state 0) and assigns the provided
 * server PID and message to the global `g_client_data`
 *  struct. It also initializes
 * the current bit, current character index, and message
 *  length to 0.
 * 
 * @param server_pid The process ID of the server to which
 *  the message will be sent.
 * @param msg The message to be sent to the server.
 */
static void	init_client_data(int server_pid, char *msg)
{
	g_client_data.state = 0;
	g_client_data.msg = msg;
	g_client_data.server_pid = server_pid;
	g_client_data.current_bit = 0;
	g_client_data.current_char = 0;
	g_client_data.current_max_bit = 0;
	g_client_data.msg_len = 0;
}

/**
 * @brief Initializes the client by validating input 
 * arguments and setting up client data.
 * 
 * This function checks if sufficient command-line arguments
 *  are provided and ensures that
 * the server PID is valid (numeric). It concatenates 
 * the arguments to form the message and
 * initializes the client data. If any error occurs, it
 *  prints an error message and exits.
 * 
 * @param argc The argument count (expected at least 3: 
 * program name, server PID, message).
 * @param argv The argument vector containing the server 
 * PID and message.
 */
static void	init_client(char **argv)
{
	int		error;
	int		server_pid;
	char	*msg;

	error = FALSE;
	server_pid = custom_atoi(argv[1], &error);
	if (error || server_pid == 0)
		exit_error("Argument mismatch. PID must be a positive integer\n",
			2);
	msg = argv[2];
	if (ft_strlen(msg) == 0)
		exit_error("No message to send\n", 2);
	init_client_data(server_pid, msg);
}

/**
 * @brief The entry point of the client application.
 * 
 * This function parses the command-line arguments, 
 * initializes the client, and sets up the
 * signal handler for receiving responses from the 
 * server. It then enters an infinite loop 
 * waiting for signals from the server, pausing the 
 * process execution between signals.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments vector.
 * @return Always returns 0, although the program is 
 * designed to run indefinitely.
 */
int	main(int argc, char **argv)
{
	if (argc != 3)
		exit_error("Incorrect args. Expect:<pid> <message>\n", 2);
	init_client(argv);
	setup_signal_handler(handle_signal_client);
	handle_state_zero_client();
	while (1)
		pause();
	return (0);
}
