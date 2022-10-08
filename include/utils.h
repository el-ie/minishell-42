/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:51:46 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 22:42:51 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/**
 * @brief Get the data object
 * 			For the  first usage init with the adress of t_data
 * 			from the main
 * 
 * 		After the initialisation you need to use it with the NULL params 
 * 
 * @param p_data  insert null for get the data 
 * 					|| insert the adress of data to set
 * @return t_data* 
 */
t_data			*get_data(t_data *p_data);
char			**get_env_addr(void);
void			set_program_params(int ac, char **av, char **envp);
void			set_program_folders(void);
char			*dup_token_to_str(t_lexer_token *token, int regular_malloc);
void			put_tokenstr_endl(t_lexer_token *token);
int				tokennstrcmp(t_lexer_token *token, char *to_comp);
void			put_lexer_token_fd(t_lexer_token *token, int fd);
int				is_envp_empty(void);
void			check_malloc_fails_safe_exit(void *node);
void			clean_exit(char *prompt);
void			free_prompt(char **prompt);
char			**free_string_array(char **array);
int				iterate_until_next_same_char_as_first(char *prompt_addr);
int				interactive_behavior(char *prompt);
void			set_and_print_err_syntax(void);
long long int	ft_atol(const char *str);

#endif
