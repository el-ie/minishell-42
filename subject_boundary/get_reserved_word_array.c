/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reserved_word_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:49:17 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 14:35:45 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*free_the_reserved_word_array(char ***array_addr)
{
	char	**array;
	int		i;

	i = 0;
	array = *array_addr;
	if (array == (char **)0)
		return ((char *)0);
	while (i < R_MAX)
	{
		free(array[i]);
		array[i] = (char *)0;
		i++;
	}
	free(array);
	array = (char **)0;
	*array_addr = array;
	return ((char *)0);
}

static void	save_reserved_word_array(char **array)
{
	array[R_IF] = ft_strdup("if");
	array[R_THEN] = ft_strdup("then");
	array[R_ELSE] = ft_strdup("else");
	array[R_ELIF] = ft_strdup("elif");
	array[R_FI] = ft_strdup("fi");
	array[R_DO] = ft_strdup("do");
	array[R_DONE] = ft_strdup("done");
	array[R_CASE] = ft_strdup("case");
	array[R_ESAC] = ft_strdup("esac");
	array[R_WHILE] = ft_strdup("while");
	array[R_UNTIL] = ft_strdup("until");
	array[R_FOR] = ft_strdup("for");
	array[R_LBRACE] = ft_strdup("{");
	array[R_RBRACE] = ft_strdup("}");
	array[R_BANG] = ft_strdup("!");
	array[R_IN] = ft_strdup("in");
}

/**
 * @brief Get the reserved word array object
 * 
 * @param index Attention input doesnt match with checker
 * 					 return value (ret value +/-=1)
 * @param free_list if 1 the content is free, for getter use 0
 * @return char*	the string value 
 */
char	*get_reserved_word_array(int index, int free_list)
{
	static char	**array = (char **)0;

	if (free_list)
		return (free_the_reserved_word_array(&array));
	if (array == (char **)0)
	{
		array = malloc(sizeof(char *) * R_MAX);
		save_reserved_word_array(array);
	}
	if (index >= R_MAX)
		return ((char *)0);
	return (array[index]);
}
