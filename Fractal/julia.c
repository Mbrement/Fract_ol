/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:22 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/10 18:25:32 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

#include <stdio.h>

#include <math.h>

// t_fract	*math(t_fract *value)
// {
// 	int		i;
// 	float	r;
// 	float	xtmp;

// 	r = 2.5;
// 	i = 0;
// 		//printf("org %f ___ %f\n", value->math.y, value->math.x);
// 	while ((value->math.x * value->math.x + value->math.y  * value->math.x < (r * r * 2) ) && i < 25000)
// 	{
// 		xtmp = (value->math.x *  value->math.x * 0.1 - value->math.y * value->math.y * 0.1);
// 		value->math.y = 2 *(value->math.x *value->math.y * 1) + value->math.y_i;
// 		value->math.x = xtmp + value->math.y_i;
// 		i++;
// 	mlx_pixel_put(value->mlx, value->window, value->math.x*300 + 1250, value->math.y*150 + 750, 0x00fffff);
// 	}
// 	//printf("%f ___ %f\n", value->math.y, value->math.x);
// 	return (value);
// }


static t_fract	*math(t_fract *value)
{
	(void) value;	
	return (value);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}



void	algo_julia(struct s_fract *value)
{
	t_data	img;
	int i;
	
	i = 0;
	value = math(value);
	img.img = mlx_new_image(value->mlx, 2500, 1500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (i < 1500)
	{
	i++;
	my_mlx_pixel_put(&img, i, i, 0xffffffff);
	mlx_put_image_to_window(value->mlx, value->window, img.img, 0, 0);
	}
sleep (3);
write (1, "pouet\n", 6);
exit(0);
}
