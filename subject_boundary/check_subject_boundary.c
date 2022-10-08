/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subject_boundary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:50:46 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 21:30:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	display_operator_error(int state)
{
	int	(*put)(char *);

	put = &put_subject_boundary_error_endl;
	if (state == 1)
		return (put("\\\' or \\\""));
	if (state == 2)
		return (put("\\\""));
	if (state == 3)
		return (put("\\\'"));
	if (state == 11)
		return (put("this operator \"<&\""));
	if (state == 12)
		return (put("this operator \">&\""));
	if (state == 13)
		return (put("this operator \"<<-\""));
	if (state == 14)
		return (put("this operator \"(\""));
	if (state == 15)
		return (put("this operator \")\""));
	return (1);
}

/**
 * @brief To-Do check subject ascii is not shure
 * 
 * @param prompt 
 * @return int 
 */
int	check_subject_boundary(char *prompt)
{
	int	state;
	int	(*put)(char *);

	put = &put_subject_boundary_error_endl;
	state = 0;
	state = check_validity_quotes(prompt);
	if (state != 0)
		return (display_operator_error(state));
	if (check_validity_ascii_printable(prompt) == 0)
		return (put("special char - only ascii char allowed"));
	if (check_validity_semicolon(prompt) == 0)
		return (put("semicolon \';\'"));
	if (check_validity_backslash(prompt) == 0)
		return (put("backslash \'\\\'"));
	state = check_validity_less_great_and(prompt);
	if (state != 0)
		return (display_operator_error(state + 10));
	if (check_validity_clobber(prompt))
		return (put("this operator \">|\""));
	return (0);
}
