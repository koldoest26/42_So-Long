/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:00:46 by luestira          #+#    #+#             */
/*   Updated: 2025/03/28 19:08:28 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_gnl(char *str)
{
	size_t	len;

	while (!str)
		return (free(str), str = NULL, 0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr_gnl(char *buffer, int c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)c)
			return ((char *)&buffer[i]);
		i++;
	}
	if (buffer[i] == (unsigned char)c)
		return ((char *)&buffer[i]);
	return (0);
}

char	*ft_strjoin_gnl(char *buffer, char *new_buffer)
{
	size_t	i;
	size_t	j;
	char	*join_buffer;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (free(buffer), buffer = NULL, NULL);
		buffer[0] = '\0';
	}
	if (!new_buffer)
		return (free(new_buffer), new_buffer = NULL, NULL);
	i = ft_strlen_gnl(buffer) + ft_strlen_gnl(new_buffer);
	join_buffer = malloc(sizeof(char) * (i + 1));
	if (!join_buffer)
		return (free(buffer), buffer = NULL, NULL);
	i = -1;
	j = 0;
	while (buffer[++i] != '\0')
		join_buffer[i] = buffer[i];
	while (new_buffer[j] != '\0')
		join_buffer[i++] = new_buffer[j++];
	return (join_buffer[i] = '\0', free(buffer), join_buffer);
}

char	*ft_read_line(char *buffer)
{
	size_t	i;
	char	*new_buffer;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i++] == '\n')
			break ;
	}
	new_buffer = malloc(sizeof(char) * (i + 1));
	if (!new_buffer)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\0' && buffer[i] != '\n')
		new_buffer[i] = buffer[i];
	if (buffer[i] == '\n')
		new_buffer[i++] = '\n';
	new_buffer[i] = '\0';
	return (new_buffer);
}

char	*ft_new_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	new_buffer = malloc(sizeof(char) * (ft_strlen_gnl(buffer) + 1));
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	return (free(buffer), buffer = NULL, new_buffer);
}
