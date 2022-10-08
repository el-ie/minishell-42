/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_eof_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:43:28 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 09:23:26 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief When the readline is empty and the ctrl-D is pressed,
 * 			This cause the closing of readline,
 * 			this function check for avoid segfault with a reading of the 
 * 			0x0 address
 *		the normal behaviour of a shell when pressing ctrl-D is to close 
 * 		the Shell
 * 		So this function do the Job with a clean exit
 * @param prompt 
 */
void	catch_eof_readline(char *prompt)
{
	if (prompt == (char *)0)
	{
		write(1, "\n", 1);
		clean_exit((char *)0);
	}
}
