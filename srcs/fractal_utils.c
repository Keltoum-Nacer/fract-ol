/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:40:21 by knacer            #+#    #+#             */
/*   Updated: 2024/02/16 15:52:04 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

double	atof(const char *str)
{
	long	in;
	double	frac;
	double	nbr;
	int		s;

	in = 0;
	frac = 0;
	s = +1;
	nbr = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			s = -s;
	while (*str != '.' && *str)
		in = (in * 10) + (*str++ - 48);
	if (*str == '.')
		++str;
	while (*str)
	{
		nbr /= 10;
		frac = frac + (*str++ - 48) * nbr;
	}
	return (s * (in + frac));
}

double	val_abs(double val)
{
	if (val >= 0)
		return (val);
	else
		return (-val);
}
