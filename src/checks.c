/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:13:09 by luestira          #+#    #+#             */
/*   Updated: 2025/05/15 14:39:20 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	if (argc != 2)
		return (ft_printf("Only 2 arguments\n"), -1);
	else
	{
		if (ft_strncmp(".ber", ft_strrchr(argv[1], '.'), 4) != 0)
		{
			ft_printf("Error. Please, introduce a correct file.\n");
			return (-1);
		}
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error. Please, try again.\n");
			close(fd);
			return (-1);
		}
		close(fd);
	}
	return (0);
}

int	counter_lines(char **argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error. Please, try again.\n");
		close(fd);
		return (-1);
	}
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	check_lines_length(int lines, char **map)
{
	int		i;
	size_t	line;
	t_map	**maps;

	line = 0;
	i = 1;
	line = ft_strlen(map[0]);
	while (i < lines)
	{
		if (ft_strlen(map[i]) != line)
			return (ft_printf("Error. Try again.\n"), 0);
		i++;
	}
	maps = malloc(sizeof(t_map));
	if (maps == NULL)
		return (0);
	free(maps);
	return (1);
}

int	check_walls(int lines, char **map)
{
	int	i;
	int	j;
	int	len;

	if (!map || lines <= 0)
		return (ft_printf("Error. Please, check the map.\n"), 0);
	len = ft_strlen(map[0]);
	if (map[0][len - 1] == '\n')
		len--;
	j = 0;
	while (j < len)
	{
		if (map[0][j] != '1' || map[lines - 1][j] != '1')
			return (ft_printf("Error. Not found top/bottom wall\n"), 0);
		j++;
	}
	i = 0;
	while (i < lines)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (ft_printf("Error: Not found side wall\n"), 0);
		i++;
	}
	return (1);
}
