/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:04:55 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 18:36:38 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief minimal spec 
 * 
 * @return int 
 */
static int	memory_minimal_requirement(void)
{
	char	*address_space;
	int		minimum;

	address_space = (char *)0;
	minimum = 64000000;
	address_space = malloc(minimum);
	if (address_space == (char *)0)
	{
		perror("minishell: 64MB minimal requirement not valid");
		return (0);
	}
	free(address_space);
	address_space = (char *)0;
	return (1);
}

void	loading_minishell(t_data *data, int argc, char **argv, char **envp)
{
	if (memory_minimal_requirement() == 0)
		exit(1);
	initialize_minishell(data, argc, argv, envp);
	if (register_signal_handler())
		clean_exit((char *)0);
	load_history_from_file();
}
