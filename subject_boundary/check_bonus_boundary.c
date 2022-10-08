/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus_boundary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:46:44 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 11:47:42 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_bonus_boundary(char *prompt)
{
	int	state;
	int	(*put)(char *);

	if (BONUS == TRUE)
		return (0);
	state = 0;
	put = &put_subject_boundary_error_endl;
	state = check_validity_bonus_andif_orif(prompt);
	if (state)
	{
		if (state == 1)
			return (put("this operator \"&&\" (bonus part)"));
		if (state == 2)
			return (put("this operator \"||\" (bonus part"));
		return (1);
	}
	return (0);
}
