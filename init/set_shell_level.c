/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shell_level.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:37:08 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 13:09:42 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	create_new_shell_level(void)
{
	set_env_by_var_name("SHLVL", "0");
}

static void	increase_shell_level(int level)
{
	char	*new_value;

	new_value = ft_itoa(level + 1);
	set_env_by_var_name("SHLVL", new_value);
	free(new_value);
	new_value = (char *)0;
}

static int	is_shell_correct(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (ft_isdigit(value[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	set_shell_level(void)
{
	char	*shell_lvl;

	shell_lvl = (char *)0;
	shell_lvl = get_env_value("SHLVL");
	if (shell_lvl == (char *)0)
		create_new_shell_level();
	shell_lvl = get_env_value("SHLVL");
	if (ft_strlen(shell_lvl) > 5)
	{
		ft_putstr_fd("warning : shell level too high\n", 2);
		create_new_shell_level();
	}
	else
	{
		if (is_shell_correct(shell_lvl) == 1)
			increase_shell_level(ft_atoi(shell_lvl));
		else
			create_new_shell_level();
	}
}
