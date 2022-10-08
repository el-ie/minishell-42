/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:21:35 by apayet            #+#    #+#             */
/*   Updated: 2022/08/22 14:14:45 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_MANAGER_H
# define HISTORY_MANAGER_H

void	load_history_from_file(void);
void	add_prompt_to_history(char *prompt, int is_exiting);

#endif