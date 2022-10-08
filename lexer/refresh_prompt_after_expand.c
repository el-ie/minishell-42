/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_prompt_after_expand.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:08:16 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 18:08:36 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*refresh_prompt_after_expand(char **new_prompt, char **prompt)
{
	if (*new_prompt != *prompt)
	{
		*prompt = free_the_prompt(prompt);
		*prompt = *new_prompt;
	}
	return (*prompt);
}
