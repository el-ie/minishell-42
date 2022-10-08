/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:33:54 by apayet            #+#    #+#             */
/*   Updated: 2022/09/19 15:30:38 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

void	*create_node(int node_type);
char	*get_type_to_string(unsigned int string_type_int);
int		get_type_to_int(char *string);
void	set_token(t_token *pin, int token_type, char *token_value);
int		array_string_length(char **array);
void	set_string_type(void);
void	set_string_ast_type(void);
char	*get_ast_type_to_string(int ast_type);
int		get_ast_type_to_int(char *string);
int		get_spec_op_value(t_list *lexer);

void	free_ast(void);

#endif
