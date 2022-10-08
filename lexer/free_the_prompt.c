/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_the_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:06:52 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 18:11:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*free_the_prompt(char **p_prompt)
{
	char	*prompt;

	prompt = *p_prompt;
	free(prompt);
	prompt = (char *)0;
	return (prompt);
}
