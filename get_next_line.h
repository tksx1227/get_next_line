/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:27:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/24 22:47:55 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# if 10000 < BUFFER_SIZE
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct s_list
{
	int				fd;
	char			*line;
	char			*temp;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
