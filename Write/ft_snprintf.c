/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:17:12 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:59 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf_utils/ft_fprintf.h"
#include "write.h"

// TODO: implementar buff e n nas várias funções
// TODO: implementar .n

/*
enum		cnt_type
{
	TOTAL;
	MAX;
}

typedef struct s_cnt
{
	int		idx;
	int		limit;
	enum	cnt_type;

}			t_cnt;

static int	push_buff(char buff[], t_cnt *cnt, char fmt, va_list al)
{
	int	count;

	count = 1;
	if (fmt == '%')
		write(fd, "%", 1);
	if (fmt == 'c')
		ft_putchar_fd(va_arg(al, int), fd);
	if (fmt == 's')
		count = ft_putstr_fd(va_arg(al, char *), fd);
	if (fmt == 'p')
		count = ft_printmemory(fd, va_arg(al, unsigned long));
	if (fmt == 'd' || fmt == 'i')
		count = ft_putnbr_fd(va_arg(al, int), fd);
	if (fmt == 'u')
		count = ft_putnbru_fd(va_arg(al, unsigned int), fd);
	if (fmt == 'x')
		count = ft_tohexa(fd, 'l', va_arg(al, unsigned long));
	if (fmt == 'X')
		count = ft_tohexa(fd, 'u', va_arg(al, unsigned long));
	return (count);
}

int	ft_snprintf(char buff[], int n, const char *fmt, ...)
{
	va_list	al;
	t_cnt	cnt;

	cnt.limit = n;
	cnt.cnt_type = TOTAL;
	cnt.idx = 0;
	if (!fmt)
		return (0);
	va_start(al, fmt);
	//TODO: implementar t_cnt nas funcs
	while (*fmt)
	{
		if (*fmt == '%')
		{
		//TODO: implementar "."
			fmt++;
			cnt.idx += push_buff(buff, n, *fmt, al);
		}
		else
		{
			buff[i] = *fmt;
			count++;
		}
		fmt++;
	}
	return (count);
}
*/

/*
int main (int c, char **v)
{
	int	n;

	n = c > 1 ? atoi(v[1]) : -1;
	//Comparar output
	printf("(printf)\n");
	int num = printf("%c || %%%s || %i || %d || %p
			|| %x || %X || %u || abc34 %%\n",
			'c', "String", n, n, (void *) &n, n, n, n);
	int num = printf("%c||%%%s||%i||%d||%p
			||%x||%X||%u%%abc",
			'c', "String", n, n, (void *)&n, n,n,n);
	//Comparar contagem
	//printf("\n(ft_printf)\n");
	//int num2 = ft_printf("%c || %%%s || %i || %d || %p
	//			|| %x || %X || %u || abc34 %%\n",
	//		'c', "String", n, n, (void *)&n, n, n, n);
	//int num2 = ft_printf("%c||%%%s||%i||%d||%p
	//			||%x||%X||%u%%abc",
	//		'c', "String", n, n, (void *)&n,n,n,n);
	//printf("\n%d || %d\n", num, num2);
}
*/
