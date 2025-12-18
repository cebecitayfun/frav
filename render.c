#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(double *z, double *c, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		c[0] = fractol->julia_x;
		c[1] = fractol->julia_y;
	}
	else
	{
		c[0] = z[0];
		c[1] = z[1];
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	double	z[2];
	double	c[2];
	double	tmp;
	int		i;
	int		clr;

	z[0] = map(x, -2.0, +2.0, WIDTH) * fractol->zoom + fractol->shift_x;
	z[1] = map(y, +2.0, -2.0, HEIGHT) * fractol->zoom + fractol->shift_y;
	mandel_vs_julia(z, c, fractol);
	i = -1;
	while (++i < fractol->iterations)
	{
		if ((z[0] * z[0]) + (z[1] * z[1]) > fractol->escape_value)
		{
			clr = ((i * 5) % 255) << 16 | ((i * 15) % 255) << 8 | (i * 20) % 255;
			my_pixel_put(x, y, &fractol->img, clr);
			return ;
		}
		tmp = (z[0] * z[0]) - (z[1] * z[1]) + c[0];
		z[1] = (2 * z[0] * z[1]) + c[1];
		z[0] = tmp;
	}
	my_pixel_put(x, y, &fractol->img, 0x000000);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window,
		fractol->img.img_ptr,
		0, 0);
}
