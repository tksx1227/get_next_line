/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:27:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/26 23:04:26 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>

# define SUCCESS 1
# define FAIL 0

typedef struct s_node
{
	int				fd;
	char			*storage;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	gnl_free(t_node **root, t_node *target);
char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
