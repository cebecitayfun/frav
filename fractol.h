#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH	800
# define HEIGHT	800

# define MANDELBROT 1
# define JULIA 2

/*
** Linux Key Codes
** ESC: 65307
*/
# define K_ESC 65307

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
} 		t_img;

typedef struct s_fractol
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	char	*name;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
} 		t_fractol;

void	print_error(void);
void	fractol_init(t_fractol *fractol);
void	fractol_render(t_fractol *fractol);
double	map(double unscaled_num, double new_min, double new_max, double old_max);
double	ft_atof(char *s);
int		ft_strcmp(char *s1, char *s2);
int		is_valid_double(char *s);
int		close_handler(t_fractol *fractol);
int		key_handler(int keysym, t_fractol *fractol);
int		mouse_handler(int button, int x, int y, t_fractol *fractol);

#endif