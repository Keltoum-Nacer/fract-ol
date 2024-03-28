/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:16:52 by knacer            #+#    #+#             */
/*   Updated: 2024/02/15 15:34:28 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->z.reel = 0.0;
			fractal->z.im = 0.0;
			fractal->c.reel = (scale(x, WIDTH, Y, X) * fractal->zoom_x)
				+ fractal->scale_x;
			fractal->c.im = (scale(y, HEIGHT, X, Y) * fractal->zoom_y)
				+ fractal->scale_y;
			check_pixel(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}

void	julia(t_fractal *fractal)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->z.reel = (scale(x, WIDTH, Y, X) * fractal->zoom_x)
				+ fractal->scale_x;
			fractal->z.im = (scale(y, HEIGHT, X, Y) * fractal->zoom_y)
				+ fractal->scale_y;
			fractal->c.reel = fractal->julia_cx;
			fractal->c.im = fractal->julia_cy;
			check_pixel(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
