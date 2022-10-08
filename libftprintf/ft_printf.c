/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:04:03 by apayet            #+#    #+#             */
/*   Updated: 2022/06/01 19:46:23 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_dispatch(t_payload *ref, const char *str, int *i)
{
	if (ref->spec)
	{
		ft_va_arg_handler(ref);
		ref[0].full_printed = ref[0].full_printed + ref[0].printed_char;
		*i = *i + ref[0].increase_i;
		*i = *i + 1;
	}
	else
		ref[0].full_printed = ref[0].full_printed + write(1, &str[*i], 1);
}

size_t	ft_printf(const char *str, ...)
{
	t_payload	payload;
	va_list		args;
	int			len;
	int			i;

	i = 0;
	len = (int)ft_strlen(str);
	va_start(args, str);
	ft_init_payload(&payload, &args);
	while (i < len)
	{
		if (!payload.spec && str[i] == '%')
			if (str[i + 1])
				payload.spec = str[i + 1];
		ft_dispatch(&payload, str, &i);
		ft_clean_payload(&payload);
		i++;
	}
	va_end(args);
	return (payload.full_printed);
}
