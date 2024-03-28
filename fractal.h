/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:45:07 by knacer            #+#    #+#             */
/*   Updated: 2024/02/15 21:37:58 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 700
# define ZOOM 400
# define ESCAPE 4
# define X 2
# define Y -2

typedef struct s_image
{
	void		*img;
	char		*adr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_complex
{
	double		reel;
	double		im;
}				t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	char		*title;
	int			max_iter;
	double		zoom_x;
	double		zoom_y;
	double		scale_x;
	double		scale_y;

	double		x;
	double		y;
	t_image		img;
	double		julia_cx;
	double		julia_cy;
	t_complex	z;
	t_complex	c;
}				t_fractal;

int				ft_strncmp(char *s1, char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
void			put_pixel(t_fractal *fractal, int x, int y, int color);
void			check_pixel(int x, int y, t_fractal *fractal);
double			scale(double val, double in_max, double out_min,
					double out_max);
t_complex		oper_complex(t_complex z, t_complex c);
void			mandelbrot(t_fractal *fractal);
double			atof(const char *str);
int				check_space_sign(const char *str);
void			julia(t_fractal *fractal);
int				mouse_hook(int mousecode, int x __attribute__((unused)),
					int y __attribute__((unused)), t_fractal *fractal);
int				magic(int button, t_fractal *fractal);
void			hook_func(t_fractal *fractal);
int				close_esc(t_fractal *fractal);
int				interpolate_color(int iter, int max_iter);
int				mouse_move(int x, int y, t_fractal *fractal);
void			burning_ship(t_fractal *fractal);
void			pixel(int x, int y, t_fractal *fractal);
double			val_abs(double val);
t_complex		burning_complex(t_complex z, t_complex c);
void			mlx_func(t_fractal *fractal);
#endif