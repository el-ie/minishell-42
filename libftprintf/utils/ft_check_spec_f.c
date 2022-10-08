/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spec_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:00:34 by apayet            #+#    #+#             */
/*   Updated: 2022/01/18 14:16:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
 * @Brief : This function search the index of the char 
 * 			inside the specifier base
 * 			It return -1 when error
 * */
int	ft_check_spec_f(char *spec_f_base, t_payload *ref)
{
	int	spec_f;

	spec_f = 0;
	while (spec_f_base[spec_f])
	{
		if (spec_f_base[spec_f] == ref[0].spec)
			return (spec_f);
		spec_f++;
	}
	return (-1);
}
