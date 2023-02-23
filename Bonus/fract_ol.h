/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:34:08 by mbrement          #+#    #+#             */
/*   Updated: 2023/02/22 06:15:43 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../Mini_libx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Tools/Libft/libft.h"

# define WIN_W 1500
# define WIN_H 750

typedef struct s_complex {
	float	x;
	float	y;
}			t_complex;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fract{
	int					fractal_nb;
	int					value;
	void				*mlx;
	void				*window;
	float				zoom;
	float				off_y;
	float				off_x;
	float				zoom_o;
	float				off_y_o;
	float				off_x_o;
	int					color;
	int					mouse;
	struct s_complex	x;
	struct s_complex	x_o;
	struct s_complex	y;
	struct s_data		*data;
}		t_fract;

//PROJECT_CORE
void			algo_init(int value, int fractal_nb);
int				hook(int key, t_fract *fract);
int				hook_mouse(int key, int x, int y, t_fract *fract);
unsigned int	ft_color(int color, struct s_fract *value);
void			my_mlx_pixel_put(t_data *data, int x, int y,
					unsigned int color);
int				loop(void *fractal);
void			init_img(t_fract *v);

//MATH
void			algo_julia(struct s_fract *value);
void			algo_mandelbrot(struct s_fract *value);
t_complex		add_complex(t_complex a, t_complex b);
t_complex		algo_cplx(t_complex a, t_complex b);
t_complex		mult_cplx(t_complex a, t_complex b);
float			module_cplx_pow2(t_complex z);
struct s_fract	fract_compleat_smandelbrot(struct s_fract *val);
void			algo_smandelbrot(struct s_fract *value);

//PARSER
int				parser(int arg_c, char **arg_v);

//ERR0R
void			ft_error(int error_code);
int				end_of_prog(t_fract *value);

#endif