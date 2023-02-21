/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:20:29 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/20 09:54:17 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	loop(void *fractal)
{
	struct s_fract			*tmp;

	tmp = fractal;
	if (tmp->off_x == 0)
		tmp->off_x = 0.01;
	if (tmp->off_y == 0)
		tmp->off_y = 0.01;
	if (tmp->fractal_nb == 1)
		algo_julia(tmp);
	else if (tmp->fractal_nb == 2)
		algo_mandelbrot(tmp);
	else if (tmp->fractal_nb == 3)
		algo_smandelbrot(tmp);
	tmp->zoom_o = tmp->zoom;
	tmp->off_y_o = tmp->off_y;
	tmp->off_x_o = tmp->off_x;
	return (0);
}

static struct s_fract	fract_compleat_julia(struct s_fract *val)
{
	val->x.x = -2;
	val->x.y = -2;
	val->y.x = -0.8 + (float)((float)val->value / 1000.0);
	val->y.y = 0.156 + (float)((float)val->value / 1000.0);
	val->zoom = 1;
	val->off_y = 0;
	val->off_x = 0.5;
	val->color = 0xffffffff;
	val->mouse = 0;
	val->zoom_o = val->zoom - 0.0001;
	val->off_y_o = val->off_y;
	val->off_y_o = val->off_x;
	return (*val);
}

static struct s_fract	fract_compleat_mandelbrot(struct s_fract *val)
{
	val->x.x = 0.0 + (float)((float)val->value / 1000.0);
	val->x.y = 0.0 + (float)((float)val->value / 1000.0);
	val->y.x = -0.1011;
	val->y.y = 0.9563;
	val->zoom = 1;
	val->x_o = val->x;
	val->color = 0xffffffff;
	val ->mouse = 0;
	val->off_y = 0;
	val->off_x = 0;
	val->off_y_o = val->off_y;
	val->off_y_o = val->off_x;
	val->zoom_o = val->zoom - 0.0001;
	return (*val);
}

void	algo_init(int value, int fractal_nb)
{
	struct s_fract	fractal;

	fractal.value = value;
	fractal.fractal_nb = fractal_nb;
	if (fractal_nb == 1)
		fractal = fract_compleat_julia(&fractal);
	else if (fractal_nb == 2)
		fractal = fract_compleat_mandelbrot(&fractal);
	else
		fractal = fract_compleat_smandelbrot(&fractal);
	fractal.mlx = mlx_init();
	if (fractal.mlx == 0)
		ft_error(4);
	fractal.window = mlx_new_window(fractal.mlx, WIN_W, WIN_H, "fract_ol");
	if (fractal.window == 0)
		ft_error(4);
	mlx_hook(fractal.window, 17, (1L << 5), end_of_prog, &fractal);
	mlx_mouse_hook(fractal.window, *hook_mouse, &fractal);
	mlx_key_hook(fractal.window, *hook, &fractal);
	loop(&fractal);
	mlx_loop(fractal.mlx);
}
