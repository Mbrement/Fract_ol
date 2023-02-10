/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:34:08 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/10 17:23:51 by mbrement         ###   ########lyon.fr   */
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

typedef struct s_complex {
	float	x;
	float	y;
}			t_complex;

typedef struct s_fract{
	int					fractal_nb;
	int					value;
	void				*mlx;
	void				*window;
	struct s_complex	x;
	struct s_complex	y;
}		t_fract;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//PROJECT_CORE
void		algo_init(int value, int fractal_nb);

//MATH
void		algo_julia(struct s_fract *value);
void		algo_mandelbrote(struct s_fract *value);
t_complex	add_complex(t_complex a, t_complex b);
t_complex	alg_cplx(float l, t_complex a, float m, t_complex b);

//PARSER
int			parser(int arg_c, char **arg_v);

//ERR0R
void		ft_error(int error_code);

#endif