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
 * @brief Exits the program with an error message.
 * 
 * This function outputs an error message to the specified file descriptor
 * and terminates the program with an exit code of 1.
 * 
 * @param msg The error message to display.
 * @param fd The file descriptor where the message will be printed.
 */
void	exit_error(char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(1);
}

/**
 * @brief Sets up the signal handler for SIGUSR1 and SIGUSR2.
 * 
 * Configures the signal handler using `sigaction` 
 * to handle both SIGUSR1 and SIGUSR2 signals.
 * The provided handler function is executed when a signal is received.
 * 
 * @param handler A function pointer to the signal handler.
 */
void	setup_signal_handler(void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}
