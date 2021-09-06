/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:28:23 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/06 18:28:24 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_gnl
{
	char			*remainder;
	int				fd;
	int				res;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

int		my_free_null(char **line, int res, char **remainder);
char	*check_remainder(char **remainder, char **line);
int		get_line(int fd, char **line, char **remainder);
t_gnl	*new_list(int fd, t_gnl *tmp);
char	*get_next_line(int fd);

char	*gnl_strjoin(char **s1, char const *s2, size_t size1, size_t size2);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *src, char **dst);
void	node_delete(t_gnl **data, t_gnl *tmp);

#endif
