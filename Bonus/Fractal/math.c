/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:25:03 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/23 12:56:44 by mbrement         ###   ########lyon.fr   */
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

t_complex	algo_cplx(t_complex a, t_complex b)
{
	t_complex	r;

	r.x = a.x + b.x;
	r.y = a.y + b.y;
	return (r);
}

t_complex	mult_cplx(t_complex a, t_complex b)
{
	t_complex	z;

	z.x = a.x * b.x - a.y * b.y;
	z.y = a.x * b.y + a.y * b.x;
	return (z);
}

float	module_cplx_pow2(t_complex z)
{
	float	m;

	m = z.x * z.x + z.y * z.y;
	return (m);
}
