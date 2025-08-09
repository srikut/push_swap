#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	output;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	output = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		output = (output * 10) + (*nptr - '0');
		nptr++;
	}
	output *= sign;
	return (output);
}