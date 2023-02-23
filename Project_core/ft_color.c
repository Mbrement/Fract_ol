/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:28:16 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/22 08:14:37 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

unsigned int	ft_color(int color, struct s_fract *value)
{
	unsigned int	rtn;

	if (color <= 26)
		rtn = INT32_MAX + value->color;
	else if (color <= 52)
		rtn = 0xffff0000 + value->color;
	else if (color <= 78)
		rtn = 0xff00ffff + value->color;
	else if (104 > color)
		rtn = 0xffff00ff + value->color;
	else
		rtn = 0xffffffff - value->color;
	return (rtn);
}
