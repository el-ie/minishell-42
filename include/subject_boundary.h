/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_boundary.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:56:25 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 11:48:44 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBJECT_BOUNDARY_H
# define SUBJECT_BOUNDARY_H

int		check_validity_quotes(char *prompt);
int		check_validity_semicolon(char *prompt);
int		check_validity_backslash(char *prompt);
int		check_validity_ascii_printable(char *prompt);
int		check_validity_less_great_and(char *prompt);
int		check_validity_clobber(char *prompt);
char	*get_reserved_word_array(int index, int free_list);
int		check_validity_bonus_andif_orif(char *prompt);

int		check_subject_boundary(char *prompt);
int		put_subject_boundary_error_endl(char *error);
int		check_bonus_boundary(char *prompt);

#endif
