/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:06:30 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 12:03:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

t_list	**get_garbage_addr(void);
t_list	*get_garbage(void);
void	clear_garbage(void);

void	*ft_malloc(size_t size);
char	*ft_strjoin_arc(char const *s1, char const *s2);
char	*ft_strdup_arc(const char *s1);
void	free_env_var_token(void);
void	free_env_dupped(int need_free);
void	free_expand_lst(void);
void	free_heredoc_list_and_erase_file(void);
void	free_loop_main(char *prompt);

#endif
