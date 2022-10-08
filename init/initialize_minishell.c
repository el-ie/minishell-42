/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:17:23 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 18:36:14 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This is the function who init the minishell instance
 * 			it check the env, the accessor for the data struct is 
 * instanciate here (for ex: get_data ...)
 * 
 * @param data 
 */
void	initialize_minishell(t_data *data, int argc, char **argv, char **envp)
{
	char	*tmp_histfile;
	char	*(*join_gc)(const char*, const char *);

	join_gc = &ft_strjoin_arc;
	ft_memset(data, 0, sizeof(t_data));
	get_data(data);
	set_program_params(argc, argv, envp);
	set_program_folders();
	parse_env();
	set_string_type();
	set_string_ast_type();
	tmp_histfile = get_env_value("HOME");
	if (tmp_histfile != (char *)0)
		data->temporary_histfile = join_gc(tmp_histfile, "/.minishell_history");
	else
		data->temporary_histfile = (char *)0;
	set_shell_level();
	get_reserved_word_array(0, FALSE);
	initialize_signal_act_array();
	set_tty_mode();
	init_builtin(data);
	if (is_interactive_mode() == 0)
		return ;
	save_terminal_config();
	set_new_terminal_config();
}
