/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:38:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:38:36 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char			c;
	static int			bits;
	static int		last_pid;

	(void)context;
	if (last_pid != info->si_pid)
	{
		c = 0;
		bits = 0;
		last_pid = info->si_pid;
	}
	if (sig == SIGUSR2)
    	c = c * 2 + 1;
	else
    	c = c * 2;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	int					pid;
	char				*pid_str;
	struct sigaction	sa;

	pid = getpid();
	pid_str = ft_itoa(pid);
	ft_putstr("Server PID: ");
	ft_putstr(pid_str);
	write(1, "\n", 1);
	free (pid_str);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
		sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr("Error: Failed to set up signal handlers\n");
		return (1);
	}
	while (1)
		pause ();
}
