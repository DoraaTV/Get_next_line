/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:16:58 by thrio             #+#    #+#             */
/*   Updated: 2022/11/25 15:26:28 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_reader(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *buffer, int BUFFER_SIZE, char *str)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	str = malloc(sizeof(char) * BUFFER_SIZE);
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	if (check_reader(buffer) == 1)
	{
		str = get_line(buffer, BUFFER_SIZE, str);
	}
	return (str);
}
