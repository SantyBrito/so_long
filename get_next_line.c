/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:35:05 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/09 14:34:50 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*cut_line(char *line)
{
	char	*output;
	int		i;

	output = ft_strchr(line, '\n');
	if (!output)
	{
		free(line);
		return (0);
	}
	i = 0;
	if (output[++i])
		output = ft_strdup(&output[i]);
	else
		output = NULL;
	free(line);
	return (output);
}

static char	*add_line(char *buff, char *line)
{
	if (!line)
		line = ft_strdup(buff);
	else
		line = edited_strjoin(line, buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line = NULL;
	char			*output;
	char			buff[BUFFER_SIZE + 1];
	int				size;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	buff[size] = '\0';
	while (size > 0)
	{
		line = add_line(buff, line);
		if (ft_strchr(line, '\n'))
			break ;
		size = read(fd, buff, BUFFER_SIZE);
		buff[size] = '\0';
	}
	output = ft_substr(line, 0, ft_strlen(line)
			- ft_strlen(ft_strchr(line, '\n')) + 1);
	line = cut_line(line);
	return (output);
}

/*
-- cut_line - a function that cuts the line at the first \n
and returns the rest of the line. If there is no \n, it returns NULL.
-- add_line - a function that adds the buffer to the line. If there is no line,
it returns a copy of the buffer. If there is a line,
it returns a copy of the line with the buffer added to the end.
-- get_next_line - a function that returns a line read from a file descriptor.
*/