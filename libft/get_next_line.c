/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:57:28 by luestira          #+#    #+#             */
/*   Updated: 2025/03/28 19:07:26 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_fd(int fd, char *buffer)
{
	char	*new_buffer;
	int		nb_read;

	new_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nb_read = 1;
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (nb_read > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		nb_read = read(fd, new_buffer, BUFFER_SIZE);
		if (nb_read > 0)
		{
			new_buffer[nb_read] = '\0';
			buffer = ft_strjoin_gnl(buffer, new_buffer);
		}
	}
	free(new_buffer);
	if (nb_read < 0)
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = ft_read_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_new_line(buffer);
	return (line);
}
/*int main (void)
{
	int	fd;
	char *line;
	int		count;

	fd = open("1.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("LINE [%d] - %s", count, line);
		count++;
		free(line);
	}
	close(fd);
	return(0);
}*/
