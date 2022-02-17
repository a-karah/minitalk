/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:14:30 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/17 17:23:00 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int signum, siginfo_t *siginfo, void *gbg)
{
	static int	out_char = 0;
	static int	pow = 0;

	(void)gbg;
	if (signum == SIGUSR1)
		out_char += 1 << (7 - pow);
	pow += 1;
	if (pow == 8)
	{
		if (out_char == 0)
		{
			if (kill(siginfo->si_pid, SIGUSR1) == -1)
				handle_error();
			out_char = 0;
			pow = 0;
			return ;
		}
		write(1, &out_char, 1);
		out_char = 0;
		pow = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			handle_error();
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = my_handler;
	if ((sigaction(SIGUSR1, &sig, 0)) == -1)
		handle_error();
	if ((sigaction(SIGUSR2, &sig, 0)) == -1)
		handle_error();
	while (1)
		pause();
	return (0);
}
