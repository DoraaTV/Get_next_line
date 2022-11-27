/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:19:26 by thrio             #+#    #+#             */
/*   Updated: 2022/11/27 16:06:02 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>


char	*get_next_line(int fd);
char	*dofree(char *res, char *buffer);
char	*getnext(char *buffer);
char	*getmyline(char *buffer);
char	*reader(int fd, char *res);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
