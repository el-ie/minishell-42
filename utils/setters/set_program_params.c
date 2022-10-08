/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_program_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:43:56 by apayet            #+#    #+#             */
/*   Updated: 2022/08/09 12:59:12 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief This function must be call inside the main
 * 			It permit to save the params into the main struct
 * 			And then can be reused
 * 
 * @param ac from main function
 * @param av from main function
 * @param envp from maihn function
 */
void	set_program_params(int ac, char **av, char **envp)
{
	t_program_params	*main_p;

	main_p = &(get_data((t_data *)0)->main);
	main_p->argc = ac;
	main_p->argv = av;
	main_p->envp = envp;
}
