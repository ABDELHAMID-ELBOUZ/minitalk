/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:37:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:39:49 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		usleep(200);
		bit--;
	}
}

void	send_text(char **av)
{
	int	pid;
	int	i;

	pid = ft_atoi(av[1]);
	i = 0;
	if (pid <= 0 || kill(pid, 0))
	{
		write(1, "Error: Invalid PID\n", 19);
		exit (1);
	}
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Error: Usage: ./client <PID> <message>\n", 39);
		return (1);
	}
	if (is_numeric(av[1]))
	{
		write(1, "Error: PID must be numeric\n", 27);
		return (1);
	}
	send_text(av);
}
