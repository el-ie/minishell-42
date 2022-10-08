/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimal_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:33:52 by apayet            #+#    #+#             */
/*   Updated: 2022/09/22 16:58:28 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*set_minimal_path(void)
{
	char				*path_line;
	int					len;
	long unsigned int	(*p)(char *, const char *, size_t);

	path_line = (char *)0;
	p = &ft_strlcpy;
	len = ft_strlen("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin");
	path_line = ft_malloc(sizeof(char) * (len + 1));
	if (path_line == (char *)0)
		return (path_line);
	len = len + 1;
	p(path_line, "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin", len);
	return (path_line);
}

static char	*set_minimal_pwd(void)
{
	char	buffer[4096];
	char	*pwd_line;
	int		len;

	getcwd(buffer, 4096);
	pwd_line = (char *)0;
	len = ft_strlen(buffer);
	pwd_line = ft_malloc(sizeof(char) * (len + 5));
	if (pwd_line == (char *)0)
		return (pwd_line);
	ft_strlcat(&pwd_line[0], "PWD=", 5);
	ft_strlcat(&pwd_line[4], buffer, len + 1);
	buffer[0] = '\0';
	return (pwd_line);
}

static char	*set_minimal_shell_level(void)
{
	char	*shlvl_line;

	shlvl_line = (char *)0;
	shlvl_line = ft_strdup_arc("SHLVL=0");
	return (shlvl_line);
}

void	create_minimal_env(void)
{
	char	**env;

	env = (char **)0;
	env = malloc(sizeof(char *) * (3 + 1));
	if (env == (char **)0)
		return ;
	env[0] = set_minimal_path();
	env[1] = set_minimal_pwd();
	env[2] = set_minimal_shell_level();
	env[3] = (char *)0;
	get_data((t_data *)0)->main.envp = env;
	get_data((t_data *)0)->main.is_env_minimal_gen = 1;
}
