/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:01:02 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/20 08:45:39 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	parser(int arg_c, char **arg_v)
{
	if (arg_c != 3)
		ft_error(1);
	if (ft_strnstr(arg_v[1], "julia", 5) && arg_v[1][5] == '\0')
		return (1);
	else if (ft_strnstr(arg_v[1], "mandelbrot", 10) && arg_v[1][10] == '\0')
		return (2);
	else if (ft_strnstr(arg_v[1], "smandelbrot", 11) && arg_v[1][11] == '\0')
		return (3);
	else
		ft_error(2);
	return (0);
}
