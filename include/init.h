/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:20 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 12:05:42 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

void	initialize_minishell(t_data *data, int argc, char **argv, char **envp);
void	set_shell_level(void);
void	loading_minishell(t_data *data, int argc, char **argv, char **envp);

#endif
