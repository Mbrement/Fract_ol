/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:22 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/22 06:20:30 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int *)dst = color;
}

void	algo_julia(struct s_fract *v)
{
	int			x;
	int			y;
	int			itr;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			itr = -1;
			v->x.x = (((float)x / WIN_W) * 3.0f - 2.0f) * v->zoom + v->off_x;
			v->x.y = (((float)y / WIN_H) * 2.5f - 1.25f) * v->zoom + v->off_y;
			while (++itr < 128 && module_cplx_pow2(v->x) < 4.0)
				v->x = algo_cplx(mult_cplx(v->x, v->x), v->y);
			my_mlx_pixel_put(v->data, x, y, ft_color(itr, v));
		}
	}
	mlx_put_image_to_window(v->mlx, v->window, v->data->img, 0, 0);
}
