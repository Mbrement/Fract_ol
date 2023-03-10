/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:51:18 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/21 04:52:13 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	hook_2(int key, t_fract *fract)
	{
	if (key == 119)
		fract->color = 0xffffffff;
	else if (key == 114)
		fract->color = 0xffff0000;
	else if (key == 98)
		fract->color = 0xff0000ff;
	else if (key == 103)
		fract->color = 0xff00ff00;
	else if (key == 109)
	{
		if (fract->mouse)
			fract->mouse = 0;
		else
			fract->mouse = 1;
	}
}

static void	hook_o(t_fract *fract)
{
	fract->off_x = 0;
	fract->off_y = 0;
	fract->zoom = 1;
	fract->color = 0xffffffff;
	fract->mouse = 0;
	if (fract->fractal_nb == 1)
	{
		fract->y.x = -0.8 + (float)((float)fract->value / 1000.0);
		fract->y.y = 0.156 + (float)((float)fract->value / 1000.0);
		fract->off_x = 0.5;
	}
	else
	{
		fract->x.x = 0.0 + (float)((float)fract->value / 1000.0);
		fract->x.y = 0.0 + (float)((float)fract->value / 1000.0);
		fract->x_o.x = fract->x.x;
		fract->x_o.y = fract->x.y;
	}
}

int	hook(int key, t_fract *fract)
{
	if (key == 65307)
	{
		end_of_prog(fract);
		mlx_loop_end(fract->mlx);
	}	
	else if (key == 65451)
		fract->zoom = fract->zoom - fract->zoom / 10;
	else if (key == 65453)
		fract->zoom = fract->zoom + fract->zoom / 10;
	else if (key == 111)
		hook_o(fract);
	else
		hook_2(key, fract);
	loop(fract);
	return (0);
}

int	hook_mouse(int key, int x, int y, t_fract *fract)
{
	if (key == 4)
		fract->zoom = fract->zoom - fract->zoom / 10;
	else if (key == 5)
		fract->zoom = fract->zoom + fract->zoom / 10;
	if (fract->mouse)
	{
		if (fract->fractal_nb == 1)
		{
			fract->y.x = -0.8 + (float)((float)fract->value / 1000.0)
				+ (float)((float)(x - ((float)WIN_H / 2)) / WIN_H);
			fract->y.y = 0.156 + (float)((float)fract->value / 1000.0)
				+(float)((float)(y - ((float)WIN_W / 2)) / WIN_W);
		}
		else
		{
			fract->x_o.x = (float)((float)fract->value
					/ 1000.0) + (float)((float)x / WIN_H);
			fract->x_o.y = (float)((float)fract->value
					/ 1000.0) + (float)((float)y / WIN_W);
		}	
	}
	loop(fract);
	return (0);
}
