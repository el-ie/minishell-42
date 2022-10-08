/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:56:01 by apayet            #+#    #+#             */
/*   Updated: 2022/09/09 08:30:49 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libcolors.h"

static size_t	ft_strlen_color(char const *const s)
{
	const char	*s_diff = s;

	while (*s_diff)
		s_diff++;
	return (s_diff - s);
}

static void	set_str_colors(char **colors_str)
{
	colors_str[RED] = "\033[0;31m";
	colors_str[CYAN] = "\033[0;36m";
	colors_str[YELLOW] = "\033[0;33m";
	colors_str[GREEN] = "\033[0;32m";
	colors_str[RESET] = "\033[0m";
}

int	colorized_state(int colors, int accessor)
{
	static int	colorized_state = 0;

	if (accessor == GET && colors == CHECK)
		return (colorized_state);
	if (accessor == SET)
	{
		if (colors == RESET)
			colorized_state = 0;
		else if (colors == CHECK)
			return (colorized_state);
		else
			colorized_state = 1;
	}
	return (colorized_state);
}

/**
 * @brief This function is designed to use color 
 * You need to call this with this enum list
 * 	RED
 *	CYAN
 *	YELLOW
 *	GREEN
 *	
 * RESET is for reset the default colors 
 * 	If you want to know if the colors is setted or not 
 *	call colorized_state(CHECK, GET)
 * 		The return value is colorized or not
 * @param colors_id 
 */
void	colors(int colors_id)
{
	char	*colors_str[MAX_COLORS];

	set_str_colors(&(colors_str)[0]);
	if (colors_id < 0 && colors_id >= MAX_COLORS)
		return ;
	write(1, colors_str[colors_id], ft_strlen_color(colors_str[colors_id]));
	colorized_state(colors_id, SET);
}
