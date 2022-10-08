/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:53:19 by apayet            #+#    #+#             */
/*   Updated: 2022/09/16 14:44:17 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "./parser_part_two.h"
/**
 * @brief Wrapped functions  
 */

char	**generate_envp_for_ast_tree(int need_free);
char	**generate_args_array_for_ast_tree(t_list *lst);
char	*get_control_string(int need_free);
int		get_id_for_ast(int reset);
void	gen_filename_redirect_fd(t_redirect **array, t_list *lst, int len);
int		get_redirect_fd_length(t_list *lst);

char	*get_command_for_ast_tree(t_list *lst);

void	register_ast_element_to_garbage(void *any_elem, int need_reset);

/**
 * @brief function handler
 * 
 */
void	set_env_to_ast_node(t_ast *ast);
void	set_control_to_ast_node(t_ast *ast);
void	set_id_to_ast_node(t_ast *ast);
void	set_ast_type_string_to_ast_node(t_ast *ast, int ast_type);
void	set_args_to_ast_node(t_ast *ast, t_list *lst);
void	set_next_to_ast_node(t_ast *ast);
void	set_command_to_ast_node(t_ast *ast, t_list *lst);
void	set_t_redirect_for_ast_node(t_ast *ast, t_list *lst);
void	set_fd_to_redirect_fd(t_redirect_fd *node);
void	set_filename_to_redirect_fd_node(t_redirect_fd *a, t_lexer_token *to);
void	set_content_to_redirect_fd_node(t_redirect **a, t_list *lst, int len);
void	set_type_to_redirect_fd_node(t_redirect_fd *node, int op_type);
void	set_op_to_redirect_fd_node(t_redirect_fd *node, t_list *lst);
void	set_t_redirect_element_to_array(t_redirect **array, int len);
void	set_mem_content_redirect_array(t_redirect **a, t_list *lst, int len);
void	set_type_for_t_redirect_array(t_redirect **a, t_list *lst, int len);
void	set_memory_content_to_t_redirect_node(t_redirect *node);
void	set_type_to_redirect_node(t_redirect *node, int type);

void	print_string_array(char **array);
void	display_t_redirect_array(t_redirect **array);
void	parser(void);

#endif