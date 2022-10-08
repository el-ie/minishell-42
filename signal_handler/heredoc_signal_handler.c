/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:34:07 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 00:53:41 by apayet           ###   ########.fr       */
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
void	heredoc_signal_handler(int sig, siginfo_t *siginfo, void *ctx)
{
	(void)sig;
	(void)siginfo;
	(void)ctx;
	get_data((t_data *)0)->status_last_cmd = SIGINT;
	reg_heredoc_garbage(NULL, TRUE);
	close(get_fd_open(GET_FD_OPEN));
	write(1, "\n", 1);
	clean_exit((char *)0);
}
