/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:22 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/13 18:04:35 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

#include <stdio.h>

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
	t_data		img;
	t_complex 	z;
	float		i;
	float 		j;
	int			itr;
	t_complex	w;


	itr = 0;
	value = math(value);
	img.img = mlx_new_image(value->mlx, 2500, 1500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	value->data = img;
	//printf("org x = %f, y = %f", value->x.x, value->x.y);
	i = -1;
	z = value->x;
	
	while (++i < 2500)
	{
		j = -1;
		w.x =i/2500;
		while (++j < 1500)
		{
				w.y = j/1500;
			while (++itr < 300 && module_cplx_pow2(z) < 4)
			{
				z = add_complex(mult_cplx(z,z), w);
				if (i + value->off_x < 2500 && j + value->off_y < 1500 && i + value->off_x > 0 && j + value->off_y > 0)
					my_mlx_pixel_put(&value->data, i + value->off_x, j + value->off_y, value->color);
			}
		//exit(0);
		}
		itr = 0;
		z = value->x;
	}
			//  printf(" end Z x = %f, y = %f\n", z.x, z.y);
		// printf("%f, %f\n", j, i);
	// exit(0);
	mlx_put_image_to_window(value->mlx, value->window, img.img, 0, 0);
	// printf(" end x = %f, y = %f\n", value->x.x, value->x.y);
	mlx_destroy_image(value->mlx, value->data.img);
}


		// my_mlx_pixel_put(&value->data, z.x+750, z.y+750, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+751, z.y+751, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+752, z.y+752, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+753, z.y+753, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+754, z.y+754, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+755, z.y+755, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+756, z.y+756, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+757, z.y+757, 0x00ffff00);
		// my_mlx_pixel_put(&value->data, z.x+758, z.y+758, 0x00ffff00);