/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:07:57 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/04 12:00:06 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	ft_error(int error_code)
{
	if (write (1, 0, 0) == -1)
		exit(0);
	write (1, "fract_ol : ", 11);
	if (error_code == 1)
		write (1, "wrong usage : ./fractol [fratal] [int]\n", 39);
	if (error_code == 2)
		write (1, "wrong usage : ./fractol [fratal] [int]\n", 39);
	exit (1);
}
