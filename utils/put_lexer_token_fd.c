/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lexer_token_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:15:53 by apayet            #+#    #+#             */
/*   Updated: 2022/08/13 12:00:48 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_lexer_token_fd(t_lexer_token *token, int fd)
{
	write(fd, token->start_address, token->length);
}
