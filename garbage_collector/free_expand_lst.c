/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expand_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:53:00 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:28:56 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_expand_lst(void)
{
	ft_lstclear(&(get_data((t_data *)0)->expand_dup_list), &free);
	get_data((t_data *)0)->expand_dup_list = (t_list *)0;
}
