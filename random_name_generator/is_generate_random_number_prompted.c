/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_generate_random_number_prompted.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:32:08 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 16:04:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_generate_random_number_prompted(char *prompt)
{
	static const char	*random_prompt = "random";
	static const size_t	length = 6;
	char				*result;

	result = (char *)0;
	result = ft_strnstr(prompt, random_prompt, length);
	if (!(result == (char *)0) && ft_strlen(prompt) == length)
	{
		printf("random file name:\"%s\"\n", random_name_generator(8, 0));
		printf("random file name:\"%s\" (hidden)\n", random_name_generator(8, 1));
		return (1);
	}
	else
		return (0);
}
