
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	main(int argc, char **argv)
{
	double	cos_x;
	int	log_x;
	int	pow_x_y;
	int	sqrt_x;

	cos_x = cos(atoi(argv[1]));
	log_x = log(atoi(argv[1]));
	pow_x_y = pow(atoi(argv[1]), atoi(argv[2]));
	sqrt_x = sqrt(atoi(argv[1]));
	printf("cos(%s) = %f\n", argv[1], cos_x);
	printf("cos(%f) = %f\n", M_PI, cos(M_PI));
	printf("log(%s) = %d\n", argv[1], log_x);
	printf("pow(%s, %s) = %d\n", argv[1], argv[2], pow_x_y);
	printf("sqrt(%s) = %d\n", argv[1], sqrt_x);
	printf("pi = %f\n", M_PI);
	return (0);
}
