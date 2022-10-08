/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_envp_for_ast_tree.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:07:59 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 15:45:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Basic free of a (char **)
 * 
 * @param stored_envp 
 * @return char** 
 */
static char	**free_generated_envp_for_ast_tree(char **stored_envp)
{
	int	i;

	i = 0;
	if (stored_envp == (char **)0)
		return (0);
	while (stored_envp[i] != (char *)0)
	{
		free(stored_envp[i]);
		stored_envp[i] = (char *)0;
		i++;
	}
	free(stored_envp);
	stored_envp = (char **)0;
	return ((char **)0);
}

// the env is exported here and need to free after command execution
// because the env is the minishell env and has update and then parsed
/**
 * @brief env is exported only one time until free is called
 * 			This is un function wrapped, please use set_env_to_ast_node 
 * 			function for the parser
 * 			Best practice is to call this function directly only 
 * 			when want to free after execution of the command
 * @param free TRUE for reset FALSE for normal call
 * @return char** 
 */
char	**generate_envp_for_ast_tree(int need_free)
{
	static char	**stored_envp = (char **)0;

	if (need_free)
		stored_envp = free_generated_envp_for_ast_tree(stored_envp);
	else
	{
		if (stored_envp == (char **)0)
			stored_envp = export_env_to_array();
	}
	return (stored_envp);
}
