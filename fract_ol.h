/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:34:08 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/04 15:53:12 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./Mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "./Tools/Libft/libft.h"

//PROJECT_CORE
void	algo_init(int value, int fractal_nb);

//PARSER
int		parser(int arg_c, char **arg_v);

//ERR0R
void	ft_error(int error_code);

#endif