#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(0);
	return (0);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == K_ESC)
		close_handler(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == 5)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
	return (0);
}
