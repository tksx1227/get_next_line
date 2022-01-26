/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:22:35 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/26 23:24:02 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
t_node	*gnl_new_node(int fd);

#endif
