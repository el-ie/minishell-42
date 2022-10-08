/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:49:04 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 21:28:34 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_execution
{
	char	*command_path;
	int		in;
	int		out;
	int		pid;
	int		cmd_validity;
	int		input_redirection_validity;
	int		input_redirection_presence;
	int		output_redirection_presence;
	int		is_builtin;
	int		is_directory;
	int		exist;
	int		executability;
	int		in_child;
}				t_execution;

#endif
