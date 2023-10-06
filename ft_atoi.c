int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int	result;
	int	signal;
	
	ptr = (char *)nptr
	result = 0;
	signal = 1;
	while (*ptr >= 9 && *ptr <= 13
			|| *ptr == 32)
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			signal *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++
	}
	return (result * signal)
}

