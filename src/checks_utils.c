/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:38 by luestira          #+#    #+#             */
/*   Updated: 2025/04/22 20:20:31 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_positions(int lines, char **map)
{
	int		i;
	int		exits;
	int		starts;
	int		collectionables;

	if (!map || lines <= 0)
		return (ft_printf("Error. Please, check the map.\n"), 0);
	i = 0;
	exits = 0;
	starts = 0;
	collectionables = 0;
	while (i < lines)
		count_line_map(map[i++], &exits, &starts, &collectionables);
	if (exits != 1 || starts != 1 || collectionables < 1)
		return (ft_printf("Error: Invalid P/E/C\n"), 0);
	return (1);
}

int	count_line_map(char *line, int *e, int *p, int *c)
{
	while (*line)
	{
		if (*line == 'E')
			(*e)++;
		else if (*line == 'P')
			(*p)++;
		else if (*line == 'C')
			(*c)++;
		else if (*line != '0' && *line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	valid_char(int lines, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != '0'
				&& map[i][j] != '1')
				return (ft_printf("Error: Invalid character\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
