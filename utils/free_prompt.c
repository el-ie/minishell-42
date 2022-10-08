/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:51:43 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 15:36:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function is designed to reduce the amount
 * 			 of instruction into the main
 * 
 * @param prompt The  prompt is the adresse of
 * 	 the pointer prompt for the set to (char *)0
 */
void	free_prompt(char **prompt)
{
	free(*prompt);
	*prompt = (char *)0;
}
