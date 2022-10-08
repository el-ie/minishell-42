/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_behavior.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:20:31 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 18:45:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	interactive_behavior(char *prompt)
{
	int		len;
	char	*str;

	if (is_interactive_mode() == 1)
		return (0);
	str = (char *)0;
	str = ft_strdup("minishell: line 2: syntax error: unexpected end of file");
	if (str == (char *)0)
		clean_exit(prompt);
	if (is_last_elem_is_pipe(prompt) == 1)
	{
		len = ft_strlen(str);
		write(2, str, len);
		get_data((t_data *)0)->status_last_cmd = 2;
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
