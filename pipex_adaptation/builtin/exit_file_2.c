/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_file_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:29:21 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 20:49:44 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long long int	ft_atol(const char *str)
{
	long long int	result;
	int				i;
	int				sign;

	if (!str)
		return (-1);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i + 1] && str[i] == '0' && ft_is_num(str[i + 1]))
		i++;
	while (str[i] && ft_is_num(str[i]))
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}
