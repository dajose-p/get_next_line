/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:30:06 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/16 20:08:55 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	leftovers(char **main_line, char *line)
{
	char	*aux;
	int		i;

	i = 0;
	while (main_line[0][i] != '\0' && main_line[0][i] != '\n')
		i++;
	if (main_line[0][i])
		i++;
	*line = ft_substr(*main_line, 0, 1);
	if (main_line[0][i])
	{
		aux = ft_substr(*main_line, i, (ft_strlen(*main_line) - i));
		free(*main_line);
		*main_line = aux;
	}
	else
	{
		free(*main_line);
		*main_line = NULL;
	}
}

static char	*new_main_line(char *main_line, int fd)
{
	char	*buffer;
	int		b_read;

	b_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(main_line, '\n') && b_read != 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == 0)
			return (NULL);
		if (b_read == -1)
		{
			free(buffer);
			free(main_line);
			return (NULL);
		}
		buffer[b_read] = '\0';
		main_line = ft_strjoin(main_line, buffer);
		if (!main_line)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (main_line);
}

char	*get_next_line(int fd)
{
	static char	*main_line = NULL;
	char		*line;

	line = NULL;
	if (fd == -1)
		return (NULL);
	main_line = new_main_line(main_line, fd);
	if (!main_line)
		return (NULL);
	leftovers(&main_line, &line);
	return (line);
}
