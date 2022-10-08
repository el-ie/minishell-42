/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctypes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:08:08 by apayet            #+#    #+#             */
/*   Updated: 2022/10/03 12:50:26 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPES_H
# define CTYPES_H

int	ft_isnum(int c);
int	ft_isalpha(int c);

int	is_char_single_quote(int c);
int	is_char_double_quote(int c);
int	is_char_semicolon(int c);
int	is_char_backslash(int c);
int	ft_isuppercase(int c);
int	ft_is_underscore(int c);
int	is_char_dollar(char c);
int	ft_islowercase(int c);
int	ft_is_space(int c);

#endif
