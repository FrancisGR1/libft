/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:20:15 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:17 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

static int	is_base(char c, int base, const char *base_str, int *value)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if (c == base_str[i] || c == base_str[i] + 32)
		{
			*value = i;
			return (YES);
		}
		i++;
	}
	return (NO);
}

int	ft_atoi_base(const char *nptr, const char *base_str)
{
	int	result;
	int	signal;
	int	base;
	int	value;

	if (!nptr || !*nptr)
		return (0);
	result = 0;
	signal = 1;
	base = ft_strlen(base_str);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal *= -1;
		nptr++;
	}
	while (is_base(*nptr, base, base_str, &value))
	{
		result = result * base + value;
		nptr++;
	}
	return (result * signal);
}
