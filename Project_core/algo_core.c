/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:20:29 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/06 15:59:00 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int i = 0;

int	loop(void *fractal)
{
	struct s_fract	*val;	

	val = fractal;
	if (val->fractal_nb == 1)
		algo_julia(val);
	else if (val->fractal_nb == 2)
		algo_mandelbrote(val);
	i++;
	if (i >= 10000)
		mlx_loop_end(val->mlx);
	return (0);
}

static struct s_fract	fract_compleat(struct s_fract val)
{
	_Complex float i;

	i = 0.655;
	val.math.x = 0.5 + (float)val.value / 1000;
	val.math.y = 0.5 + (float)val.value / 1000;
	val.math.x_i = i;
	val.math.y_i = i;
	return (val);
}

void	algo_init(int value, int fractal_nb)
{
	struct s_fract	fractal;

	fractal.value = value;
	fractal.fractal_nb = fractal_nb;
	fractal.mlx = mlx_init();
	fractal = fract_compleat(fractal);
	if (fractal.mlx == 0)
		ft_error(4);
	fractal.window = mlx_new_window(fractal.mlx, 2500, 1500, "fract_ol");
	if (fractal.window == 0)
		ft_error(4);
	mlx_loop_hook(fractal.mlx, loop, &fractal);
	mlx_loop(fractal.mlx);
}
