/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warn_heredoc_ctrl_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:50:08 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 11:41:23 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	warn_heredoc_ctrl_d(t_heredoc *hdoc, int current_counted)
{
	ft_putstr_fd("\nminishell : warning : here-document at line ", 1);
	ft_putnbr_fd(current_counted, 1);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 1);
	ft_putstr_fd(hdoc->limiter, 1);
	ft_putstr_fd("')\n", 1);
}
