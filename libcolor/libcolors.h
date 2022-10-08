/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:53:27 by apayet            #+#    #+#             */
/*   Updated: 2022/06/22 16:39:47 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLORS_H
# define LIBCOLORS_H
# include <unistd.h>
# include <stdio.h>

typedef enum e_get_set
{
	GET,
	SET,
	CHECK = -1,
}			t_get_set;

typedef enum e_colors
{
	RED,
	CYAN,
	YELLOW,
	GREEN,
	RESET,
	MAX_COLORS,
}			t_colors;

int		colorized_state(int colors, int accessor);
void	colors(int colors_id);
// char	*get_str_colors(int colors, char **p_colors_str);

#endif