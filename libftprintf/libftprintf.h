/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:39:30 by apayet            #+#    #+#             */
/*   Updated: 2022/06/01 19:35:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef enum e_switch
{
	CHAR,
	STRING,
	POINTER,
	DIGIT,
	IDIGIT,
	UINT,
	HEX,
	SHIFT_HEX,
	PRINT_POURCENT,
	ENUM_MAX
}		t_switch;

typedef struct s_payload
{
	va_list					*list;
	size_t					full_printed;
	char					spec;
	size_t					printed_char;
	void					*value;
	char					c;
	char					*s;
	int						d;
	unsigned long long int	u;
	unsigned long long int	p;
	unsigned long long int	x;
	int						increase_i;
}				t_payload;

void	ft_clean_payload(t_payload *ref);
void	ft_init_payload(t_payload *ref, va_list *list);
int		ft_check_spec_f(char *spec_f_base, t_payload *ref);
void	ft_put_uint_fd(unsigned long int n, int fd);
size_t	ft_uintlen(unsigned long long int value, size_t base_len);
size_t	ft_intlen(long long int value, size_t base_len);
void	ft_itoa_base(u_int64_t value, char *res, char *base, size_t len_p);
void	ft_convert_c_format(t_payload *ref);
void	ft_convert_p_format(t_payload *ref);
void	ft_convert_s_format(t_payload *ref);
void	ft_ignore_specifier_format(t_payload *ref);
void	ft_convert_di_format(t_payload *ref);
void	ft_convert_u_format(t_payload *ref);
void	ft_convert_x_format(t_payload *ref);
void	ft_get_char(t_payload *ref);
void	ft_get_string(t_payload *ref);
void	ft_get_pointer(t_payload *ref);
void	ft_get_digit(t_payload *ref);
void	ft_get_uint(t_payload *ref);
void	ft_get_x(t_payload *ref);
void	ft_get_ignore_spec(t_payload *ref);
void	ft_va_arg_handler(t_payload *ref);

void	ft_funct_handler(t_payload *ref);
void	ft_dispatch(t_payload *ref, const char *str, int *i);
size_t	ft_printf(const char *str, ...);
#endif
