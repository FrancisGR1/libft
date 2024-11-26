/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:20:37 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/17 21:52:05 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include "../../libft.h"

int		ft_putnbru_fd(unsigned int n, int fd);
int		ft_tohexa(int fd, char to_format, unsigned long n);
int		ft_printmemory(int fd, unsigned long n);
int		ft_fprintf(int fd, const char *str, ...);
#endif
