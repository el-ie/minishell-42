/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:59:10 by eamar             #+#    #+#             */
/*   Updated: 2022/10/03 22:59:13 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_builtin_fp_array(t_data *data)
{
	data->builtin_functions[0] = &builtin_echo;
	data->builtin_functions[1] = &builtin_cd;
	data->builtin_functions[2] = &builtin_pwd;
	data->builtin_functions[3] = &builtin_export;
	data->builtin_functions[4] = &builtin_unset;
	data->builtin_functions[5] = &builtin_env;
	data->builtin_functions[6] = &builtin_exit;
	data->builtin_functions[7] = NULL;
}

void	init_builtin(t_data *data)
{
	data->builtin_list[0] = ft_strdup_arc("echo");
	data->builtin_list[1] = ft_strdup_arc("cd");
	data->builtin_list[2] = ft_strdup_arc("pwd");
	data->builtin_list[3] = ft_strdup_arc("export");
	data->builtin_list[4] = ft_strdup_arc("unset");
	data->builtin_list[5] = ft_strdup_arc("env");
	data->builtin_list[6] = ft_strdup_arc("exit");
	data->builtin_list[7] = NULL;
	init_builtin_fp_array(data);
}
