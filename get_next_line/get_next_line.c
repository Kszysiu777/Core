/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:21:51 by kbizon            #+#    #+#             */
/*   Updated: 2024/04/21 10:38:56 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *str)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_line = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new_line[j++] = str[i++];
	new_line[j] = '\0';
	free(str);
	return (new_line);
}

char	*ft_next_line(char *str)
{
	char	*next_line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	next_line = (char *)malloc((i + 2) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		next_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		next_line[i] = str[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_reader(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while ((!ft_strchr(str, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_reader(fd, str);
	if (!str)
		return (NULL);
	if (str[0] == 0)
		return (NULL);
	next_line = ft_next_line(str);
	str = ft_new_line(str);
	return (next_line);
}

/* int main()
{
	char *string;
	int fd = open("txt", O_RDONLY);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	close(fd);
} */