/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:19:56 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/25 10:13:21 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_read(int fd, char **line)
{
	ssize_t	rc;
	char	*buf;

	while (1)
	{
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1 || rc == 0)
		{
			free(buf);
			if (rc == 0)
				return (SUCCESS);
			else
				return (FAIL);
		}
		buf[rc] = '\0';
		*line = ft_strjoin(*line, buf);
		free(buf);
		if (ft_strchr(*line, '\n') != NULL)
			return (SUCCESS);
	}
}
