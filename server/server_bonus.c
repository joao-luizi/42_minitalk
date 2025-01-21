/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:26:34 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/14 13:29:47 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk_bonus.h"

t_server_data	*g_server_data;

/**
 * @brief Frees the node associated with a specific client PID.
 * 
 * This function traverses the linked list of server data and 
 * removes the node corresponding to the given client process ID.
 * 
 * @param client_pid The process ID of the client whose data should be freed.
 */
void	free_node(int client_pid)
{
	t_server_data	*temp;
	t_server_data	*prev;

	temp = g_server_data;
	prev = NULL;
	if (!temp)
		return ;
	while (temp)
	{
		if (temp->client_pid == client_pid)
		{
			if (prev)
				prev->next = temp->next;
			else
				g_server_data = temp->next;
			free(temp->message);
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

/**
 * @brief Finds the server data node for the given client PID.
 * 
 * This function searches the linked list of server data for the node
 * associated with the given client process ID. If no node exists, 
 * it creates a new one.
 * 
 * @param client_pid The process ID of the client.
 * @return A pointer to the found or newly created server data node.
 */
t_server_data	*find_node(int client_pid)
{
	t_server_data	*temp;
	t_server_data	*prev;

	temp = g_server_data;
	if (!temp)
	{
		g_server_data = new_server_data(client_pid);
		return (g_server_data);
	}
	while (temp)
	{
		if (temp->client_pid == client_pid)
			return (temp);
		prev = temp;
		temp = temp->next;
	}
	temp = new_server_data(client_pid);
	if (!temp)
		return (NULL);
	prev->next = temp;
	return (temp);
}

/**
 * @brief Creates and initializes a new server data node for a client.
 * 
 * Allocates memory for a new `t_server_data` struct, initializes its 
 * fields, and sets the client PID. 
 * 
 * @param client_pid The process ID of the client.
 * @return A pointer to the newly created server data 
 * node, or NULL if allocation fails.
 */
t_server_data	*new_server_data(int client_pid)
{
	t_server_data	*new;

	new = malloc(sizeof(t_server_data));
	if (!new)
		return (NULL);
	new->client_pid = client_pid;
	new->current_bit = 0;
	new->current_max_bits = 0;
	new->current_char = 0;
	new->message = NULL;
	new->message_length = 0;
	new->state = 0;
	new->next = NULL;
	return (new);
}

/**
 * @brief Main server loop.
 * 
 * Prints the server's process ID, sets up the signal handler, and
 * enters an infinite loop waiting for signals.
 * 
 * @return Always returns 0.
 */
int	main(void)
{
	ft_printf("%d\n", getpid());
	setup_signal_handler(handle_signal_server);
	while (1)
		pause();
	return (0);
}
