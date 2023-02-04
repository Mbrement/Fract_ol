/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:05:49 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/04 15:53:03 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Tools/Libft/libft.h"
#include "fract_ol.h"

int	main(int arg_c, char **arg_v)
{
	int	value;
	int	fractal_nb;

	fractal_nb = parser(arg_c, arg_v);
	value = ft_atoi(arg_v[2]);
	algo_init(value, fractal_nb);
	sleep(2);
	return (0);
}
