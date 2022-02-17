/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:12:49 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/17 17:34:48 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, int chr)
{
	int	mask;

	mask = 128;
	while (mask)
	{
		if (mask & chr)
		{
			if (kill(pid, SIGUSR1) == -1)
				handle_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				handle_error();
		}
		mask /= 2;
		usleep(100);
	}
}

void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(pid, msg[i]);
		++i;
	}
	ft_putstr_fd("Total bytes sent = ", 1);
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
	i = 8;
	while (i)
	{
		send_byte(pid, 0);
		--i;
	}
}

void	my_handler(int signum, siginfo_t *siginfo,	void *gbg)
{
	static int	recv = 0;

	(void)signum;
	(void)siginfo;
	(void)gbg;
	if (signum == SIGUSR2)
		++recv;
	else if (signum == SIGUSR1)
	{
		ft_putstr_fd("Ack received from server!\n", 1);
		ft_putstr_fd("Total bytes received from server = ", 1);
		ft_putnbr_fd(recv, 1);
		write(1, "\n", 1);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig;
	int					pid;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = my_handler;
	if (argc != 3)
	{
		ft_putstr_fd("Yanlis arguman sayisi\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid || pid < 0)
		handle_error();
	if ((sigaction(SIGUSR1, &sig, 0)) == -1)
		handle_error();
	if ((sigaction(SIGUSR2, &sig, 0)) == -1)
		handle_error();
	send_msg(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
