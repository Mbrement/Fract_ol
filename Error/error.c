/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:07:57 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/12 14:13:52 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	end_of_prog(t_fract *value)
{
	if (value->mlx)
	{
		if (value->window)
			mlx_destroy_window(value->mlx, value->window);
		mlx_destroy_display(value->mlx);
		free(value->mlx);
	}
	exit(0);
}


void	ft_error(int error_code)
{
	int	fd;

	fd = 1;
	if (write (1, 0, 0) == -1)
	{
		if (write(2, 0, 0) == -1)
			exit(0);
		write(2, "output 1 is close\n", 18);
		fd = 2;
	}
	write (fd, "fract_ol : ", 11);
	if (error_code == 1)
		write (fd, "wrong usage : ./fractol [fratal] [int]\n", 39);
	if (error_code == 2)
		write (fd, "wrong usage : only 'julia' or 'mandelbrote'\n", 44);
	if (error_code == 3)
		write (fd, "wrong usage : int in second parameter\n", 38);
	if (error_code == 4)
		write (fd, "mlx couldn't start\n", 19);
	exit (1);
}
