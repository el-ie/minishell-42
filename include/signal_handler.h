/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:45:18 by apayet            #+#    #+#             */
/*   Updated: 2022/09/23 08:15:30 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

void	signal_handler(int sig, siginfo_t *siginfo, void *context);
void	catch_eof_readline(char *prompt);
int		register_signal_handler(void);
int		reset_signal_handler_to_default(void);
int		register_default_signal_handler(void);
int		ignore_signal_handler(void);
void	heredoc_signal_handler(int sig, siginfo_t *siginfo, void *ctx);
void	initialize_signal_act_array(void);
int		register_heredoc_signal_handler(void);
void	pipe_signal_handler(int sig, siginfo_t *siginfo, void *ctx);
int		register_pipe_signal_handler(void);
int		return_value_of_child(int status);

#endif
