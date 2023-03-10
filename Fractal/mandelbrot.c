/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:58 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/22 03:36:47 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	algo_mandelbrot(struct s_fract *v)
{
	int			c[3];	

	c[0] = -1;
	while (++c[0] < WIN_H)
	{
		c[1] = -1;
		v->y.y = (((float)c[0] / WIN_H) * 2.5f - 1.25f) * v->zoom + v->off_y;
		while (++c[1] < WIN_W)
		{
			c[2] = -1;
			v->y.x = (((float)c[1] / WIN_W) * 3.0f - 2.0f) * v->zoom + v->off_x;
			while (++c[2] < 128 && module_cplx_pow2(v->x) < 4)
				v->x = algo_cplx(mult_cplx(v->x, v->x), v->y);
			v->x = v->x_o;
			my_mlx_pixel_put(v->data, c[1], c[0], ft_color(c[2], v));
		}
	}
	mlx_put_image_to_window(v->mlx, v->window, v->data->img, 0, 0);
}
