/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:01 by knacer            #+#    #+#             */
/*   Updated: 2024/03/22 00:06:18 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	burning_complex(t_complex z, t_complex c)
{
	t_complex	res;

	res.reel = z.reel * z.reel - z.im * z.im + c.reel;
	res.im = -2 * z.reel * z.im + c.im;
	return (res);
}

void	pixel(int x, int y, t_fractal *fractal)
{
	int	i;
	int	color;

	i = 0;
	while ((fractal->z.reel * fractal->z.reel + fractal->z.im
			* fractal->z.im < ESCAPE) && i < fractal->max_iter)
	{
		fractal->z = burning_complex(fractal->z, fractal->c);
		i++;
	}
	color = interpolate_color(i, fractal->max_iter + 22);
	if (i == fractal->max_iter)
	{
		put_pixel(fractal, x, y, 0x000000);
	}
	else
	{
		put_pixel(fractal, x, y, color);
	}
}

void	burning_ship(t_fractal *fractal)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->z.reel = 0.0;
			fractal->z.im = 0.0;
			fractal->c.reel = (scale(x, WIDTH, X, Y) * fractal->zoom_x)
				+ fractal->scale_x;
			fractal->c.im = (scale(y, HEIGHT, Y, X) * fractal->zoom_y)
				+ fractal->scale_y;
			pixel(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
