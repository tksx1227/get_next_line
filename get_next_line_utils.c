/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:48:18 by ttomori           #+#    #+#             */
/*   Updated: 2022/01/26 23:06:19 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(const char *s, size_t size)
{
	size_t	i;
	size_t	len;
	char	*p;

	len = ft_strlen(s);
	if (len < size)
		size = len;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len[2];
	char	*p;
	char	*temp;
	char	*head;

	if (s1 == NULL)
		return (ft_strndup(s2, ft_strlen(s2)));
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	if (SIZE_MAX - len[0] <= len[1])
	{
		free(s1);
		return (NULL);
	}
	p = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1));
	head = p;
	temp = s1;
	while (p != NULL && *s1 != '\0')
		*p++ = *s1++;
	while (p != NULL && *s2 != '\0')
		*p++ = *s2++;
	if (p != NULL)
		*p = '\0';
	free(temp);
	return (head);
}

void	gnl_free(t_node **root, t_node *target)
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
