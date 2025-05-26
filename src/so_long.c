/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:47:17 by luestira          #+#    #+#             */
/*   Updated: 2025/05/26 13:39:35 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**save_map(int lines, char **argv)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n"), NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (free_map(map, i), NULL);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	checking_main_utils(int lines, char **map)
{
	if (!check_walls(lines, map))
		return (1);
	if (!check_lines_length(lines, map))
		return (1);
	if (!check_positions(lines, map))
		return (1);
	if (!check_path(lines, map))
		return (1);
	if (!map || !map[0] || map[0][0] == '\0' || map[0][0] == '\n')
	{
		ft_printf("Error: Empty first line\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		lines;
	int		cols;

	if (check_args(argc, argv) == -1)
		return (1);
	lines = counter_lines(argv);
	if (lines <= 0)
		return (ft_printf("Error: Invalid line count\n"), 1);
	map = save_map(lines, argv);
	if (!map)
		return (ft_printf("Error: Couldn't save map\n"), 1);
	if (checking_main_utils(lines, map))
	{
		free_map(map, lines);
		return (1);
	}
	cols = ft_strlen(map[0]);
	start_game(map, lines, cols);
	free_map(map, lines);
	return (0);
}
