/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:27:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/30 15:47:09 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <errno.h>

# define SUCCESS 1
# define FAIL 0

typedef struct s_node
{
	int				fd;
	char			*storage;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t size);
char	*ft_strjoin_with_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);
t_node	*gnl_new_node(int fd);

#endif
