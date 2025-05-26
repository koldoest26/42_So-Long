/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:06:58 by luestira          #+#    #+#             */
/*   Updated: 2025/05/26 13:10:00 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**dup_map(char **map, int lines)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * lines);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (free_map(copy, i), NULL);
		i++;
	}
	return (copy);
}

void	find_player(char **map, int *y, int *x)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int y, int x, int lines)
{
	if (y < 0 || x < 0 || y >= lines || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] != 'C' || map[y][x] != 'E')
		map[y][x] = 'F';
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, lines);
	flood_fill(map, y - 1, x, lines);
	flood_fill(map, y, x + 1, lines);
	flood_fill(map, y, x - 1, lines);
}

int	path_is_valid(char **map, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(int lines, char **map)
{
	char	**copy;
	int		x;
	int		y;

	copy = dup_map(map, lines);
	if (!copy)
		return (ft_printf("Error\n"), 0);
	find_player(copy, &y, &x);
	flood_fill(copy, y, x, lines);
	if (!path_is_valid(copy, lines))
		return (free_map(copy, lines), ft_printf("Error: No valid path\n"), 0);
	free_map(copy, lines);
	return (1);
}
