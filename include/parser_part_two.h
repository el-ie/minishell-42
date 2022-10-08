/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_part_two.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:57:46 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 11:01:22 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PART_TWO_H
# define PARSER_PART_TWO_H

/**
 * @brief This header is a part file of parser.h 
 * 			this contain non-primitive return value
 * 			created for validate the norme 
 * 			was error : more than 80 character line 
 */

t_ast		*go_to_t_redirect_for_ast_node(t_redirect **array);
t_list		*iter_lst_until_pipe(t_list *lst);
t_redirect	**generate_t_redirect_for_ast_tree(t_list *lst);

#endif