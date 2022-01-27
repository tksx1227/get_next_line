/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:19:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/26 23:21:55 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		gnl_read(t_node	*node);
static t_node	*gnl_get_node(int fd, t_node **root);
static void		gnl_free(t_node **root, t_node *target);
static char		*gnl_reformat_line(t_node *node, int status);

char	*get_next_line(int fd)
{
	int				status;
	char			*line;
	t_node			*node;
	static t_node	*root;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (root == NULL)
	{
		root = gnl_new_node(fd);
		if (root == NULL)
			return (NULL);
	}
	node = gnl_get_node(fd, &root);
	status = gnl_read(node);
	if (status == FAIL)
	{
		gnl_free(&root, node);
		return (NULL);
	}
	line = gnl_reformat_line(node, status);
	if (line == NULL || *(node->storage) == '\0')
		gnl_free(&root, node);
	return (line);
}

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
				return (SUCCESS);
			return (FAIL);
		}
		buf[rc] = '\0';
		node->storage = ft_strjoin_with_free(node->storage, buf);
		free(buf);
		if (node->storage == NULL)
			return (FAIL);
	}
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
	node->prev = prev;
	return (node);
}

static char	*gnl_reformat_line(t_node *node, int status)
{
	char	*temp;
	char	*line;
	char	*target;

	if (status == FAIL || node == NULL)
		return (NULL);
	target = ft_strchr(node->storage, '\n');
	if (target == NULL)
	{
		line = node->storage;
		node->storage = ft_strndup("", 0);
		return (line);
	}
	temp = node->storage;
	line = ft_strndup(temp, target - temp + 1);
	node->storage = ft_strndup(target + 1, ft_strlen(target + 1));
	free(temp);
	if (node->storage == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static void	gnl_free(t_node **root, t_node *target)
{
	t_node	*prev;
	t_node	*next;

	if (root == NULL || *root == NULL || target == NULL)
		return ;
	prev = target->prev;
	next = target->next;
	if (prev != NULL)
	{
		prev->next = next;
		if (next != NULL)
			next->prev = prev;
	}
	else
	{
		*root = next;
		if (next != NULL)
			next->prev = NULL;
	}
	free(target->storage);
	free(target);
}
