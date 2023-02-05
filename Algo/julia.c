/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:22 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/05 16:06:48 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

#include <stdio.h>


static float	*math(int value)
{
	int		i;
	float	z;
	float	*tab;
	float	tmp;

	i = 0;
	z = 0;
	tmp = value;
	tab = malloc(sizeof(float) * 25);
	while (i < 25)
	{
		tab[i] = (z * z + (tmp / 100));
		z = tab[i];
		i++;
	}
	i = 0;
	while (i < 25)
	{
		printf("%f\n", tab[i]);
		i++;
	}
	exit(0);
	return (tab);
}

void	algo_julia(struct s_fract *value)
{
	int		i;
	float	*tab;

	i = 0;
	tab = math(value->value);
	while (i < 2500)
	{
		mlx_pixel_put(value->mlx, value->window, 2500 - i, i, 0xff0000ff);
		mlx_pixel_put(value->mlx, value->window, i, i, 0xff0000ff);
		i++;
	}
	free(tab);
}
