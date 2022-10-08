/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:53:51 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 11:10:00 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief	Because the ft_iter function require only one param,
 * 			We use this static variable that conserve the previous fd
 * 			See enum e_const
 * 			 To re-init just put -1 to fd params
 * 			else return the previous stored fd
 * 
 * 
 * 			The logic is
 * 				* the fisrt time the function is called
 * 						the opened_fd is eq to RESET_GET_FD_OPEN
 * 
 * 						normal usage : fd is not eq to RESET_GET_FD_OPEN
 * 							assignement of opened_fd with the value of fd
 * 						return opened_fd so the same value of fd
 *				* the other time call the function with GET_FD_OPEN
						the GET_FD_OPEN is for getting a friendly usage
						you get the fd from the first call of the function
			Call the function with RESET_GET_FD_OPEN will reset the logic so 
			before call another filedescriptor you need the function with 
				RESET_GET_FD_OPEN
			and then the logic restart as the first call of the function
			You can after close the filedescriptor call with RESET_GET_FD_OPEN
 * @param fd 
 * @return int 
 */
int	get_fd_open(int fd)
{
	static int	opened_fd = RESET_GET_FD_OPEN;

	if (opened_fd == RESET_GET_FD_OPEN)
		opened_fd = fd;
	return (opened_fd);
}
