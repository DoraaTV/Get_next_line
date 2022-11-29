/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:01:44 by thrio             #+#    #+#             */
/*   Updated: 2022/11/29 11:13:22 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*dofree(char *res, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(res, buffer);
	free(res);
	return (tmp);
}

char	*getnext(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
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
	int		i;

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
	char	*buffer;
	int		bytenb;

	if (!res)
		res = ft_calloc(1, 1);
	if (ft_strchr(res, '\n'))
		return (res);
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
	static char	*buffer[1024];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = reader(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	str = getmyline(buffer[fd]);
	buffer[fd] = getnext(buffer[fd]);
	return (str);
}
