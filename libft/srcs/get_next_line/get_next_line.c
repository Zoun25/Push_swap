/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:47:26 by ysadki-z          #+#    #+#             */
/*   Updated: 2024/03/07 10:47:28 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_reader(int fd, char *file_return)
{
	int		bytes;
	char	*file;

	bytes = 1;
	file = NULL;
	while (bytes > 0 && !ft_strchr_gnl(file, '\n'))
	{
		file = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
		if (file == NULL)
			return (NULL);
		bytes = read(fd, file, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (file_return)
				free(file_return);
			free(file);
			file = NULL;
			return (NULL);
		}
		file_return = ft_strjoin_gnl(file_return, file);
		free(file);
		file = NULL;
	}
	return (file_return);
}

char	*ft_newline(char *file)
{
	char	*line;
	int		n;

	n = 0;
	while (file[n] && file[n] != '\n')
		n++;
	if (file[n] == '\n')
		n++;
	line = ft_substr_gnl(file, 0, n);
	return (line);
}

char	*ft_freefile(char *file, char *line)
{
	char	*newfile;
	int		l;

	if (!file || !line)
		return (NULL);
	l = 0;
	while (file[l] == line[l] && file[l])
		l++;
	newfile = ft_substr_gnl(file, l, ft_strlen_gnl(file) - l);
	free(file);
	return (newfile);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = ft_reader(fd, file);
	if (file == NULL || file[0] == '\0')
	{
		if (file)
			free(file);
		return (file = NULL, NULL);
	}
	line = ft_newline(file);
	file = ft_freefile(file, line);
	return (line);
}
