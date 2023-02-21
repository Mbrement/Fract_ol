/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:58 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/20 08:41:05 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	algo_boat(struct s_fract *v)
{
	float		tmp;
	t_data		img;
	int			c[2];
	int			itr;

	img.img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	v->data = &img;
	c[0] = -1;
	while (++c[0] < WIN_H)
	{
		c[1] = -1;
		v->y.y = (((float)c[0] / WIN_H) * 2.5f - 1.25f) * v->zoom + v->off_y;
		while (++c[1] < WIN_W)
		{
			itr = -1;
			v->y.x = (((float)c[1] / WIN_W) * 3.0f - 2.0f) * v->zoom + v->off_x;
			while (itr < 64 && module_cplx_pow2(v->x) < 4)
			{
				tmp = (float)abs((int)(v->x.x * v->x.x - v->x.y * v->x.y)) + v->y.x;
				v->x.y = (v->x.x+v->x.y) * (v->x.x * v->x.y) - v->y.y;
				v->x.x = tmp;
				itr++;
			}
			v->x = (t_complex){0, 0};
			my_mlx_pixel_put(v->data, c[1], c[0], ft_color(itr, v));
		}
	}
	mlx_put_image_to_window(v->mlx, v->window, v->data->img, 0, 0);
	mlx_destroy_image(v->mlx, v->data->img);
}
