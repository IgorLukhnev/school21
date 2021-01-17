/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:04:22 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/17 14:41:59 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int			already_printed;
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			hash;
	int			plus;
	int			space;
}				t_flags;

int				ft_printf(const char *str, ...);
int				ft_is_type(int c);
int				ft_is_flag(int c);
int				ft_resolver(int c, t_flags flags, va_list args);
int				ft_resolve_width(int width, int minus, int has_zero);
int				ft_putnstr(char *str, int n);
int				ft_resolve_ch(char c, t_flags flags);
int				ft_resolve_str(char *str, t_flags flags);
int				ft_resolve_int(int i, t_flags flags);
int				ft_resolve_percent(t_flags flags);
int				ft_resolve_hexa(unsigned int ui, int lower, t_flags flags);
int				ft_resolve_uint(unsigned int ui, t_flags flags);
int				ft_resolve_dot(const char *save, int start, t_flags *flags,
		va_list args);
int				ft_putchar(int c);
int				ft_resolve_ptr(unsigned long long ptr, t_flags flags);

char			*ft_ull_base(unsigned long long ull, int base);
char			*ft_uitoa(unsigned int n);
char			*ft_strtolower(char *str);

t_flags			ft_flag_minus(t_flags flags);
t_flags			ft_flag_width(va_list args, t_flags flags);
t_flags			ft_flag_digit(char c, t_flags flags);
int				ft_dot_flag(const char *input, int start,
		t_flags *flags, va_list args);

#endif
