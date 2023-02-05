/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:34:08 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/05 14:39:04 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./Mini_libx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "./Tools/Libft/libft.h"

typedef struct s_fract{
	int		fractal_nb;
	int		value;
	void	*mlx;
	void	*window;
}	t_fract;

//PROJECT_CORE
void	algo_init(int value, int fractal_nb);

//Algorithm
void	algo_julia(struct s_fract *value);
void	algo_mandelbrote(struct s_fract *value);

//PARSER
int		parser(int arg_c, char **arg_v);

//ERR0R
void	ft_error(int error_code);

#endif