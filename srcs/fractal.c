/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:29:59 by knacer            #+#    #+#             */
/*   Updated: 2024/02/16 15:53:57 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int ac, char **av)
{
	t_fractal	fractol;

	if ((ac == 2 && (!ft_strncmp(av[1], "Mandelbrot", 10) || !ft_strncmp(av[1],
					"burningship", 11))) || (ac == 4 && !ft_strncmp(av[1],
				"julia", 5)))
	{
		fractol.title = av[1];
		mlx_func(&fractol);
		if (!ft_strncmp(fractol.title, "Mandelbrot", 10))
			mandelbrot(&fractol);
		else if (!ft_strncmp(fractol.title, "julia", 5) && ac == 4)
		{
			fractol.julia_cx = atof(av[2]);
			fractol.julia_cy = atof(av[3]);
			julia(&fractol);
		}
		else if (!ft_strncmp(fractol.title, "burningship", 11))
			burning_ship(&fractol);
		hook_func(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		ft_putstr_fd("error, the parameters that you can use are : \n"
			"<Mandelbrot>\n <julia> <arg1> <arg2> \n<burningship>",
			1);
}
