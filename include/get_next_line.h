/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:58:53 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 00:38:06 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

typedef struct s_gnl
{
	char	*res;
	int		do_ret;
	int		fd;
}			t_gnl;

void	*ft_free(void *bloc);
int		ft_line_len(char *buff, int fstrlen);
size_t	custom_strcpy(char *dest, char *src);
char	*ft_strjoin_gnl(char *swap, char *buffer);
char	*ft_strndup(char *buff, size_t size);

char	*get_next_line_need_free(char **swap, int *last_line, int need_reset);
void	check_nl(char **swap, int *last_line, t_gnl *m);
void	update_res(char **swap, int line_len, t_gnl *m);
void	swap_add(char **swap, int *last_line, t_gnl *m, char *buffer);
void	update_swap(char **swap, char *buffer);
char	*get_next_line(int fd, int need_reset);

#endif
