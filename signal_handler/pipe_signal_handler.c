/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_signal_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:07:35 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 18:39:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief this iss inside the fork, so wait pid will multiply by CHILD_COEF 256
 * 
 * @param sig 
 * @param siginfo 
 * @param ctx 
 */
void	pipe_signal_handler(int sig, siginfo_t *siginfo, void *ctx)
{
	(void)sig;
	(void)siginfo;
	(void)ctx;
	get_data((t_data *)0)->status_last_cmd = SIGINT;
	write(1, "\n", 1);
	clean_exit(NULL);
}
