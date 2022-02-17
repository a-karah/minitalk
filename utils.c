/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:14:49 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/17 12:14:50 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	if (!s)
		return ;
	write(fd, s, i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		++i;
	}
	return (sign * res);
}

void	handle_error(void)
{
	ft_putstr_fd("Signal error!\n", 1);
	exit(0);
}
