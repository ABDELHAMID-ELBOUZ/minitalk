/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:37:57 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:38:07 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

int		is_numeric(char *str);
void	send_char(int pid, char c);
void	send_text(char **av);
void	signal_handler(int sig, siginfo_t *info, void *context);
void	ft_putstr(char *str);
char	*ft_itoa(int num);
int		ft_atoi(const char *str);

#endif
