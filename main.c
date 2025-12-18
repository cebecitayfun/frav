#include "fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (NULL == fractol->mlx_connection)
		exit(1);
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			WIDTH, HEIGHT,
			fractol->name);
	if (NULL == fractol->mlx_window)
	{
		exit(1);
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (NULL == fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		exit(1);
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp,
			&fractol->img.line_len,
			&fractol->img.endian);
	mlx_hook(fractol->mlx_window, 17, 0, close_handler, fractol);
	mlx_key_hook(fractol->mlx_window, key_handler, fractol);
	mlx_mouse_hook(fractol->mlx_window, mouse_handler, fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		fractol.name = argv[1];
		if (!ft_strcmp(fractol.name, "julia"))
		{
			if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
			{
				write(1, ERROR_MESSAGE, 95);
				exit(1);
			}
			fractol.julia_x = ft_atof(argv[2]);
			fractol.julia_y = ft_atof(argv[3]);
		}
		fractol_init(&fractol);
		data_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		write(1, ERROR_MESSAGE, 95);
		exit(1);
	}
	return (0);
}
