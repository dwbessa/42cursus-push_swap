/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:46:28 by dbessa            #+#    #+#             */
/*   Updated: 2023/11/23 11:30:33 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*save_new_line(char *store)
{
	char	*save;
	size_t	new_line_size;
	size_t	i;

	i = 0;
	new_line_size = 1;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	if (ft_strchr(store, 10))
		new_line_size = ft_strlen(ft_strchr(store, 10) + 1) + 1;
	save = malloc(new_line_size);
	if (!save)
		return (NULL);
	if (ft_strchr(store, 10))
		ft_strlcpy(save, ft_strchr(store, 10) + 1, new_line_size);
	else
		ft_strlcpy(save, store, new_line_size);
	free(store);
	return (save);
}

static char	*actual_line(char *store)
{
	size_t	ret_size;
	char	*ret;
	size_t	len;

	if (!*store)
		return (NULL);
	len = 0;
	while (store[len] && store[len] != '\n')
		len++;
	ret_size = (len + 2);
	ret = malloc(ret_size);
	if (!ret)
		return (NULL);
	ret_size = ft_strlcpy(ret, store, ret_size);
	return (ret);
}

static char	*read_line(char *store, int fd)
{
	int		read_len;
	char	*temp;

	read_len = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (read_len > 0 && !ft_strchr(store, 10))
	{
		read_len = read(fd, temp, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[read_len] = '\0';
		store = ft_strjoin(store, temp);
	}
	free(temp);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[MAX_FD];
	char		*ret;

	if ((fd < 0 || BUFFER_SIZE <= 0) || read(fd, &ret, 0) < 0)
		return (NULL);
	store[fd] = read_line(store[fd], fd);
	if (!store[fd])
		return (NULL);
	ret = actual_line(store[fd]);
	store[fd] = save_new_line(store[fd]);
	return (ret);
}
