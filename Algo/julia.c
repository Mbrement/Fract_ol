/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:22 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/06 16:00:41 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

#include <stdio.h>

#include <math.h>

t_fract	*math(t_fract *value)
{
	int		i;
	float	r;
	float	xtmp;

	r = 2.5;
	i = 0;
		//printf("org %f ___ %f\n", value->math.y, value->math.x);
	while ((value->math.x * value->math.x + value->math.y  * value->math.x < (r * r * 2) ) && i < 25000)
	{
		xtmp = (value->math.x *  value->math.x * 0.1 - value->math.y * value->math.y * 0.1);
		value->math.y = 2 *(value->math.x *value->math.y * 1) + value->math.y_i;
		value->math.x = xtmp + value->math.y_i;
		i++;
	mlx_pixel_put(value->mlx, value->window, value->math.x*300 + 1250, value->math.y*150 + 750, 0x00fffff);
	}
	//printf("%f ___ %f\n", value->math.y, value->math.x);
	return (value);
}

void	algo_julia(struct s_fract *value)
{
	// int		i;
	// // float	*tab;

	// i = 0;
	value = math(value);
	// while (i < 2500)
	// {
	// 	mlx_pixel_put(value->mlx, value->window, 2500 - i, i, 0xfffffff);
	// 	mlx_pixel_put(value->mlx, value->window, i, i, 0xff0000ff);
	// 	i++;
	// }
	// free(tab);
}
