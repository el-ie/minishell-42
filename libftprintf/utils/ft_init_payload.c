/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_payload.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:30:33 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:17:00 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_init_payload(t_payload *ref, va_list *list)
{
	ref[0].full_printed = 0;
	ref[0].list = list;
	ref[0].spec = '\0';
	ref[0].printed_char = 0;
	ref[0].c = '\0';
	ref[0].s = (char *)0;
	ref[0].d = 0;
	ref[0].p = 0;
	ref[0].u = 0;
	ref[0].x = 0;
	ref[0].value = (void *)0;
	ref[0].increase_i = 0;
}
