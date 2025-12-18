#include "fractol.h"

int	is_valid_double(char *s)
{
	int	has_dot;

	has_dot = 0;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
