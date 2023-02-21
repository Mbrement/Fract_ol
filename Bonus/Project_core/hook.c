/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:51:18 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/21 08:36:01 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	hook_2(int key, t_fract *fract)
	{
	if (key == 65362)
		fract->off_y = fract->off_y + 0.01;
	else if (key == 65364)
		fract->off_y = fract->off_y - 0.01;
	else if (key == 65361)
		fract->off_x = fract->off_x + 0.01;
	else if (key == 65363)
		fract->off_x = fract->off_x - 0.01;
	else if (key == 119)
		fract->color = 0xffffffff;
	else if (key == 114)
		fract->color = 0xffff0000;
	else if (key == 98)
		fract->color = 0xff0000ff;
	else if (key == 103)
		fract->color = 0xff00ff00;
	else if (key == 99)
		fract->color = rand();
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

#include <stdio.h>

int	hook_mouse(int key, int x, int y, t_fract *fract)
{
		printf("O = %f | %f\n", fract->off_x, fract->off_y);
	if (key == 4)
	{
		// fract->off_x = (((float)WIN_H/2) - (((float)WIN_H-x)/2))/1000;
		fract->off_y = (((float)WIN_W/2) - (((float)WIN_W-y)/2))/1000;
		fract->zoom = fract->zoom - fract->zoom / 10;
		printf("- = %f | %f\n", fract->off_x, fract->off_y);
	}
	else if (key == 5)
	{
		// fract->off_x = (((float)WIN_H/2) - ((float)WIN_H/2))/1000;
		fract->off_y = (((float)WIN_W/2) - ((float)WIN_W/2))/1000;
		fract->zoom = fract->zoom + fract->zoom / 10;
		printf("+ = %f | %f\n", fract->off_x, fract->off_y);
	}
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
