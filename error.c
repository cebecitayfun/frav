#include "fractol.h"

void	print_error(void)
{
	write(1, "Please enter:\n", 14);
	write(1, "\t./fractol mandelbrot\n", 22);
	write(1, "\t./fractol julia <real> <imag>\n", 31);
	exit(1);
}
