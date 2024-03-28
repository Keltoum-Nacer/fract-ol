/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:53:10 by knacer            #+#    #+#             */
/*   Updated: 2024/02/15 21:29:05 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	scale(double val, double in_max, double out_min, double out_max)
{
	return ((val - 0) * (out_max - out_min) / (in_max - 0) + out_min);
}

void	put_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*pix;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pix = fractal->img.adr + (y * fractal->img.line_length + x
				* (fractal->img.bpp / 8));
		*(unsigned int *)pix = color;
	}
}

t_complex	oper_complex(t_complex z, t_complex c)
{
	t_complex	res;

	res.reel = z.reel * z.reel - z.im * z.im + c.reel;
	res.im = 2 * z.reel * z.im + c.im;
	return (res);
}

int	interpolate_color(int iter, int max_iter)
{
	int		color;
	int		c1;
	int		c2;
	int		c3;
	double	t;

	t = (double)iter / max_iter;
	c1 = (int)(255 * (1 - t) * ((0x00FF00 >> 13) & 0x00000F) + t
			* ((0xFF0000 >> 16) & 0x00000F));
	c2 = (int)(255 * (1 - t) * ((0x00FF00 >> 8) & 0xFF) + t
			* ((0xFF0000 >> 10) & 0xFF));
	c3 = (int)(255 * (1 - t) * (0x00FF00 & 0x0000FF) + t
			* (0xFF0000 & 0x0000FF));
	color = (c3 << 16) | (c2 << 8) | c1;
	return (color);
}

void	check_pixel(int x, int y, t_fractal *fractal)
{
	int	i;
	int	color;

	i = 0;
	while ((fractal->z.reel * fractal->z.reel + fractal->z.im
			* fractal->z.im < ESCAPE) && i < fractal->max_iter)
	{
		fractal->z = oper_complex(fractal->z, fractal->c);
		i++;
	}
	color = interpolate_color(i, fractal->max_iter + 22);
	if (i == fractal->max_iter)
		put_pixel(fractal, x, y, 0x000000);
	else
		put_pixel(fractal, x, y, color);
}
