/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:53:13 by knacer            #+#    #+#             */
/*   Updated: 2024/02/16 15:58:49 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_hook(int mousecode, int x __attribute__((unused)),
		int y __attribute__((unused)), t_fractal *fractal)
{
	if (mousecode == 4)
	{
		fractal->zoom_x *= 0.85;
		fractal->zoom_y *= 0.85;
	}
	else if (mousecode == 5)
	{
		fractal->zoom_y /= 0.85;
		fractal->zoom_x /= 0.85;
	}
	if (!ft_strncmp(fractal->title, "Mandelbrot", 10))
	{
		mandelbrot(fractal);
	}
	else if (!ft_strncmp(fractal->title, "julia", 5))
		julia(fractal);
	else
		burning_ship(fractal);
	return (0);
}

int	close_esc(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}

int	magic(int button, t_fractal *fractal)
{
	if (button == 53)
		close_esc(fractal);
	if (button == 69)
		fractal->max_iter += 1;
	else if (button == 78)
		fractal->max_iter -= 2;
	else if (button == 124)
		fractal->scale_x -= (0.5 * fractal->zoom_x);
	else if (button == 123)
		fractal->scale_x += (0.5 * fractal->zoom_x);
	else if (button == 125)
		fractal->scale_y += (0.5 * fractal->zoom_y);
	else if (button == 126)
		fractal->scale_y -= (0.5 * fractal->zoom_y);
	if (!ft_strncmp(fractal->title, "Mandelbrot", 10))
		mandelbrot(fractal);
	else if (!ft_strncmp(fractal->title, "julia", 5))
		julia(fractal);
	else
		burning_ship(fractal);
	return (0);
}

int	mouse_move(int x, int y, t_fractal *fractal)
{
	fractal->julia_cx = scale(x, WIDTH, Y, X) * fractal->zoom_x;
	fractal->julia_cy = scale(y, HEIGHT, X, Y) * fractal->zoom_y;
	if (!ft_strncmp(fractal->title, "julia", 5))
		julia(fractal);
	return (0);
}

void	hook_func(t_fractal *fractal)
{
	mlx_hook(fractal->win, 4, 0, mouse_hook, fractal);
	mlx_hook(fractal->win, 2, 0, magic, fractal);
	mlx_hook(fractal->win, 6, 0, mouse_move, fractal);
	mlx_hook(fractal->win, 17, 0, close_esc, fractal);
}
