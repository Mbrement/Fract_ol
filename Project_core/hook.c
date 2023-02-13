/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:51:18 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/13 13:31:22 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

#include <stdio.h>

int	hook(int key, t_fract *fract)
{
	// printf("%i\n", key);
	// write (1, "d", 1);
	if (key == 65307)
	{
		end_of_prog(fract); 
		mlx_loop_end(fract->mlx);
	}	
	else if (key == 65451 && fract->zoom < 1490)
		fract->zoom = fract->zoom + 10;
	else if (key == 65453 && fract->zoom >= 10)
		fract->zoom = fract->zoom - 10;
	else if (key == 65362)
		fract->off_y = fract->off_y - 10;
	else if (key == 65364)
		fract->off_y = fract->off_y + 10;
	else if (key == 65361)
		fract->off_x = fract->off_x - 10;
	else if (key == 65363)
		fract->off_x = fract->off_x + 10;
	else if (key == 65363)
		fract->off_x = fract->off_x + 10;
	else if (key == 119)
		fract->color = 0xffffffff;
	else if (key == 114)/*R*/
		fract->color = 0xffff0000;
	else if (key == 98)/*B*/
		fract->color = 0xff0000ff;
	else if (key == 103)/*G*/
		fract->color = 0xff00ff00;
	return (1);
}
	