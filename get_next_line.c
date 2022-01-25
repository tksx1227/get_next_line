/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:19:56 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/25 22:33:03 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_read(t_node	*node)
{
	ssize_t	rc;
	char	*buf;

	if (node == NULL)
		return (FAIL);
	while (1)
	{
		if (ft_strchr(node->storage, '\n') != NULL)
			return (SUCCESS);
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		rc = read(node->fd, buf, BUFFER_SIZE);
		if (rc == -1 || rc == 0)
		{
			free(buf);
			if (rc == 0)
				return (FINISH);
			return (FAIL);
		}
		buf[rc] = '\0';
		node->storage = ft_strjoin(node->storage, buf);
		free(buf);
		if (node->storage == NULL)
			return (FAIL);
	}
}

static t_node	*gnl_new_node(int fd)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->storage = NULL;
	node->next = NULL;
	return (node);
}

static t_node	*gnl_get_node(int fd, t_node **root)
{
	t_node	*node;
	t_node	*prev;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		node = gnl_new_node(fd);
		*root = node;
		return (node);
	}
	node = *root;
	while (node != NULL)
	{
		if (node->fd == fd)
			return (node);
		prev = node;
		node = node->next;
	}
	node = gnl_new_node(fd);
	prev->next = node;
	return (node);
}
