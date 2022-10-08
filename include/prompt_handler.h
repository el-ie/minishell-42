/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:46:12 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:29:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_HANDLER_H
# define PROMPT_HANDLER_H

int		is_last_elem_is_pipe(char *prompt);
int		is_prompt_empty(char *prompt);

char	*get_display_prompt(void);
char	*pipe_prompt(char *prompt);
char	*prompt_selector(void);
int		pipe_prompt_handler(char **p_prompt);

#endif
