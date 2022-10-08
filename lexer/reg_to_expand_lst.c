/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_to_expand_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:46:16 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:08:53 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*reg_to_expand_lst(char *elem)
{
	t_data	*data;

	data = get_data((t_data *)0);
	ft_lstadd_back(&(data->expand_dup_list), ft_lstnew((void *)elem));
	return (elem);
}
