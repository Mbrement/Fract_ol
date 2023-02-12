/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:20:29 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/12 17:42:03 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

#include <stdio.h>


int	loop(void *fractal)
{
	struct s_fract	*val;	

	val = fractal;
	if (val->fractal_nb == 1)
		algo_julia(val);
	else if (val->fractal_nb == 2)
		algo_mandelbrote(val);
	return (0);
}

static struct s_fract	fract_compleat_julia(struct s_fract *val)
{
	val->x.x = -2;
	val->x.y = -2;
	val->y.x = -0.8;
	val->y.y = 0.156;
	val->zoom = 0;
	val->off_y = 750;
	val->off_x = 1250;
	val->color = 0xffffffff;
	return (*val);
}

void	algo_init(int value, int fractal_nb)
{
	struct s_fract	fractal;

	fractal.value = value;
	fractal.fractal_nb = fractal_nb;
	if (fractal_nb == 1)
		fractal = fract_compleat_julia(&fractal);
	fractal.mlx = mlx_init();
	if (fractal.mlx == 0)
		ft_error(4);
	fractal.window = mlx_new_window(fractal.mlx, 2500, 1500, "fract_ol");
	if (fractal.window == 0)
		ft_error(4);
	mlx_loop_hook(fractal.mlx, loop, &fractal);
	mlx_key_hook(fractal.window, *hook, &fractal);
	mlx_loop(fractal.mlx);
}
