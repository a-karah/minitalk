/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:15:01 by akarahan          #+#    #+#             */
/*   Updated: 2022/02/17 12:15:03 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_PID 99998

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);;
void	handle_error(void);

#endif
