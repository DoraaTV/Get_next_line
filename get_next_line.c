/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:16:58 by thrio             #+#    #+#             */
/*   Updated: 2022/11/27 17:35:29 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dofree(char *res, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(res, buffer);
	free(res);
	return (tmp);
}

char	*getnext(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if(!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*getmyline(char *buffer)
{
	char	*line;
	int	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] || buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*reader(int fd, char *res)
{
	char 	*buffer;
	int	bytenb;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytenb = 1;
	while (bytenb > 0)
	{
		bytenb = read(fd, buffer, BUFFER_SIZE);
		if (bytenb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytenb] = 0;
		res = dofree(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = reader(fd, buffer);
	if (!buffer)
		return (NULL);
	str = getmyline(buffer);
	buffer = getnext(buffer);
	return (str);
}
