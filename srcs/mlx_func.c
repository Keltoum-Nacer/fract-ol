/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:31:14 by knacer            #+#    #+#             */
/*   Updated: 2024/02/16 15:54:31 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mlx_func(t_fractal *fractal)
{
	fractal->max_iter = 100;
	fractal->zoom_x = 1.1;
	fractal->zoom_y = 1.1;
	fractal->scale_x = 0.0;
	fractal->scale_y = 0.0;
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
	{
		free(fractal->mlx);
		exit(0);
	}
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->title);
	if (fractal->win == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
	}
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->img.adr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.line_length, &fractal->img.endian);
}
