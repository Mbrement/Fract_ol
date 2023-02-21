/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:28:16 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/20 05:40:33 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

unsigned int	ft_color(int color, struct s_fract *value)
{
	unsigned int	rtn;

	if (color <= 128 / 5)
		rtn = INT32_MAX + value->color;
	else if (color <= 128 / 5)
		rtn = 0xff00ff00 + value->color;
	else if (color <= (128 / 5) * 2)
		rtn = 0xffff0000 + value->color;
	else if (color <= (128 / 5) * 3)
		rtn = 0xff00ffff + value->color;
	else if (color <= (128 / 5) * 4)
		rtn = 0xffff00ff + value->color;
	else
		rtn = 0xffffffff - value->color;
	return (rtn);
}
