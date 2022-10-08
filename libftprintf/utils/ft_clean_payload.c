/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_payload.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:54:36 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:16:44 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_clean_payload(t_payload *ref)
{
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
