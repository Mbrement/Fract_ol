/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:25:03 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/10 13:52:04 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	rtn;

	rtn.x = a.x + b.y;
	rtn.y = a.y + b.y;
	return (rtn);
}

t_complex	alg_cplx(float l, t_complex a, float m, t_complex b)
{
	t_complex	r;

	r.x = l * a.x + m * b.x;
	r.y = l * a.y + m * b.y;
	return (r);
}