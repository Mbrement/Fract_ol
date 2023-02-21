/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:07:57 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/21 19:02:00 by mbrement         ###   ########lyon.fr   */
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
		mlx_destroy_image(value->mlx, value->data->img);
		// mlx_destroy_image(value->mlx, value->data_tmp->img);
		free(value->data);
		// free(value->data_tmp);
	}
	exit(0);
}

void	ft_error(int error_code)
{
	int	fd;
	int	i;

	fd = 1;
	if (write (1, 0, 0) == -1)
	{
		if (write(2, 0, 0) == -1)
			exit(0);
		i = write(2, "output 1 is close\n", 18);
		fd = 2;
	}
	i = write (fd, "fract_ol : ", 11);
	if (error_code == 1)
		i = write (fd, "wrong usage : ./fractol [fratal] [int]\n", 39);
	if (error_code == 2)
		i = write (fd, "wrong usage : only 'julia' or 'mandelbrot'\n", 43);
	if (error_code == 3)
		i = write (fd, "wrong usage : int in second parameter\n", 38);
	if (error_code == 4)
		i = write (fd, "mlx couldn't start\n", 19);
	(void)i;
	exit (1);
}
