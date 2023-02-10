/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:58 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/10 15:15:44 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

#include <stdio.h>


// static t_fract	*math(t_fract *value)
// {
// 	int i;

// 	while (i < 10000)
// 	{
// 	value->math.x = value->math.x + 1 *-0.1011;
// 	value->math.y = value->math.y + 1 * 0.9563;
// 	mlx_pixel_put(value->mlx, value->window,
// 		value->math.x*3 + 1250, value->math.y*1.5 +750, 0x00fffff);
// 	i++	;
// 	}
// 	return (value);
// }
// static t_fract	*math(t_fract *value)
// {
// 	int		i;
// 	float	r;
// 	float	xtmp;

// 	r = 2.5;
// 	i = 0;
// 	value->math.y = 0;
// 	value->math.x = 0;
// 		//printf("org %f ___ %f\n", value->math.y, value->math.x);
// 	while ((value->math.x * value->math.x + value->math.y
// 			* value->math.x < r*r) && i < 10000)
// 	{
// 		xtmp = value->math.x * value->math.x -value->math.y * value->math.y + (float)value->value / 1000;
// 		value->math.y = 2 * value->math.x*value->math.y + (float)value->value / 1000;
// 		value->math.x = xtmp;
// 		i++;
// 		mlx_pixel_put(value->mlx, value->window,
// 				value->math.x*3000 + 1250, value->math.y*1500 +750, 0x00ff0000);
// 		// mlx_pixel_put(value->mlx, value->window,
// 		// 		value->math.x*300 + 1250, value->math.y*150 +750, 0x00fffff);
// 	}
// 	//printf("x:%f ___ y:%f\n", value->math.y, value->math.x);
// 	return (value);
// }
void	algo_mandelbrote(struct s_fract *value)
{
	(void)value;
	// value=math(value);
}