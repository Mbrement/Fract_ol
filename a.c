void	algo_julia(struct s_fract *value)
{
	t_data		img;
	t_complex 	z;
	float			i;
	float 		j;
	int			itr;
	t_complex	y;


	itr = 0;
	value = math(value);
	img.img = mlx_new_image(value->mlx, 2500, 1500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	value->data = img;
	//printf("org x = %f, y = %f", value->x.x, value->x.y);
	i = -1;
	// z.x = value->zoom * -1 / 1500;
	while (++i < 2500)
	{
		z = value->x;
		j = -1;
		while (++j < 1500)
		{
		y.x = (i /2500) * 2500;
		y.y = (j /1500) * 1500;

			while (++itr < 300 && module_cplx_pow2(z) < 4)
			{
				z = add_complex(mult_cplx(z, z), y);
			if (z.x + value->off_x < 2500 && z.y + value->off_y < 1500 && z.x + value->off_x > 0 && z.y + value->off_y > 0)
				my_mlx_pixel_put(&value->data, i, j, value->color);
			}
		z = value->x;
		itr = 0;
		}
	}
	write(1, "done\n", 5);
	mlx_put_image_to_window(value->mlx, value->window, img.img, 0, 0);
	// printf(" end Z x = %f, y = %f\n", z.x, z.y);
	//printf(" end x = %f, y = %f\n", value->x.x, value->x.y);
	mlx_destroy_image(value->mlx, value->data.img);
}