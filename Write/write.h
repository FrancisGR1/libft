/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:16:16 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:16:51 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include "../libft.h"

void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putns(char *s, int n);
void	ft_puts(const char *s);
int		ft_putnbr_fd(int n, int fd);
int		ft_snprintf(char buff[], int n, const char *fmt, ...);
int		ft_fprintf(int fd, const char *str, ...);
void	print_bits(char c, int fd);

#endif /*WRITE_H*/
