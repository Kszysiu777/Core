/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:21:51 by kbizon            #+#    #+#             */
/*   Updated: 2024/04/24 13:55:41 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char **buffer)
{
	char	*newline;
	char	*temp;
	int		i;

	i = 0;
	if (!*buffer)
		return (NULL);
	temp = *buffer;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	newline = ft_substr(temp, 0, i);
	*buffer = ft_substr(temp, i, ft_strlen(temp) - i);
	if (temp)
		free(temp);
	temp = NULL;
	return (newline);
}

char	*write_to_buffer(char *buffer, int fd)
{
	char	*new;
	int		read_bytes;

	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !new)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, new, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
		{
			free(new);
			free(buffer);
			return (NULL);
		}
		new[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, new);
	}
	if (new)
		free(new);
	new = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*newline;

	newline = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (free(buffer), buffer = NULL, NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		buffer[0] = '\0';
	}
	buffer = write_to_buffer(buffer, fd);
	newline = ft_new_line(&buffer);
	return (newline);
}

/* int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
} */
