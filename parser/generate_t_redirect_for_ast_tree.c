/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_t_redirect_for_ast_tree.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:46:13 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 12:45:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redirect	**generate_t_redirect_for_ast_tree(t_list *lst)
{
	t_redirect		**array;
	int				array_length;

	array = (t_redirect **)0;
	array_length = get_redirect_fd_length(lst);
	if (array_length == 0)
		return ((t_redirect **)0);
	array = malloc(sizeof(t_redirect *) * (array_length + 1));
	check_malloc_fails_safe_exit((void *)array);
	set_t_redirect_element_to_array(array, array_length);
	set_type_for_t_redirect_array(array, lst, array_length);
	set_mem_content_redirect_array(array, lst, array_length);
	set_content_to_redirect_fd_node(array, lst, array_length);
	gen_filename_redirect_fd(array, lst, array_length);
	display_t_redirect_array(array);
	return (array);
}
