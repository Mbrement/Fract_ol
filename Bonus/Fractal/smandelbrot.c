/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smandelbrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 04:54:38 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/20 09:57:06 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

struct s_fract	fract_compleat_smandelbrot(struct s_fract *val)
{
	val->x.x = 0.0 + (float)((float)val->value / 1000.0);
	val->x.y = 0.0 + (float)((float)val->value / 1000.0);
	val->y.x = -0.1011;
	val->y.y = 0.9563;
	val->zoom = 1;
	val->x_o = val->x;
	val->color = 0xffffffff;
	val ->mouse = 0;
	val->off_x = 0;
	val->off_y = 0;
	val->off_y_o = val->off_y;
	val->off_y_o = val->off_x;
	val->zoom_o = val->zoom - 0.0001;
	return (*val);
}

t_complex	ft_smand(t_fract *fract)
{
	int			i;
	t_complex	c;

	c = fract->x;
	i = -1;
	while (i++ < fract->value - 1)
		c = mult_cplx(c, fract->x);
	return (c);
}

void	algo_smandelbrot(struct s_fract *v)
{
	int			c[3];	
	t_data		img;

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
			c[2] = -1;
			v->y.x = (((float)c[1] / WIN_W) * 3.0f - 2.0f) * v->zoom + v->off_x;
			while (++c[2] < 128 && module_cplx_pow2(v->x) < 4)
				v->x = algo_cplx(1, ft_smand(v), 1, v->y);
			v->x = v->x_o;
			my_mlx_pixel_put(v->data, c[1], c[0], ft_color(c[2], v));
		}
	}
	mlx_put_image_to_window(v->mlx, v->window, v->data->img, 0, 0);
	mlx_destroy_image(v->mlx, v->data->img);
}
