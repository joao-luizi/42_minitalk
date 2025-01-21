/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:26:10 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 15:52:13 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>
# include "../lib/libft/include/libft.h"

typedef struct s_client_data
{
	char	*msg;
	int		state;
	int		server_pid;
	int		current_char;
	int		current_bit;
	int		current_max_bit;
	size_t	msg_len;
}	t_client_data;

typedef struct s_server_data
{
	size_t					message_length;
	char					*message;
	int						current_bit;
	int						current_max_bits;
	int						current_char;
	int						client_pid;
	int						state;
	struct s_server_data	*next;
}	t_server_data;

extern t_server_data	*g_server_data;
extern t_client_data	g_client_data;

int				custom_atoi(char *str, int *error);
char			**parse_command_line_arguments(int *argc,
					char **argv, char separator);
char			*join_strings_with_separator(int start_index,
					char **argv, char separator);
void			free_args(char **str);

void			setup_signal_handler(void (*handler)(int, siginfo_t *, void *));
void			handle_signal_server(int sig, siginfo_t *info, void *context);
void			handle_signal_client(int sig, siginfo_t *info, void *context);
void			handle_state_zero_client(void);
void			exit_error(char *msg, int fd);

t_server_data	*new_server_data(int client_pid);
t_server_data	*find_node(int client_pid);
void			free_node(int client_pid);

#endif 
