/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:20:29 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/04 16:19:45 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	algo_init(int value, int fractal_nb)
{
	void	*test;

	(void) value;
	(void) fractal_nb;
	test = mlx_init();
	if (test == 0)
		ft_error(4);
	if (mlx_new_window(test, 2500, 1500, "fract_ol") == 0)
		ft_error(4);
}
