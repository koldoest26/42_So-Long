/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:51:36 by luestira          #+#    #+#             */
/*   Updated: 2025/05/26 15:23:24 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_images(t_game *g)
{
	int	s;

	s = 60;
	g->sprites[0]
		= mlx_xpm_file_to_image(g->mlx, "textures/rink.xpm", &s, &s);
	g->sprites[1]
		= mlx_xpm_file_to_image(g->mlx, "textures/puck.xpm", &s, &s);
	g->sprites[2]
		= mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &s, &s);
	g->sprites[3]
		= mlx_xpm_file_to_image(g->mlx, "textures/cone.xpm", &s, &s);
	g->sprites[4]
		= mlx_xpm_file_to_image(g->mlx, "textures/net.xpm", &s, &s);
}

void	start_game(char **map, int lines, int cols)
{
	t_game	*g;
	t_map	*map_data;

	g = malloc(sizeof(t_game));
	map_data = malloc(sizeof(t_map));
	if (start_game_checker(g, map_data))
		return ;
	map_data->map = map;
	map_data->lines = lines;
	map_data->width = cols;
	g->map = map_data;
	g->moves = 0;
	g->collectibles = count_collectibles(g->map->map);
	g->player_x = 0;
	g->player_y = 0;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, cols * 60, lines * 60, "so_long");
	if (!g->mlx || !g->map || !g->win)
		return (free(map_data), free(g), (void)0);
	load_images(g);
	render_map(g);
	mlx_hook(g->win, 2, 1L << 0, handle_key, g);
	mlx_hook(g->win, 17, 0, close_game, g);
	mlx_key_hook(g->win, handle_exit, g);
	mlx_loop(g->mlx);
}

void	render_tile(t_game *g, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->sprites[3], x, y);
	else if (tile == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->sprites[0], x, y);
	else if (tile == 'P')
	{
		g->player_x = x / 60;
		g->player_y = y / 60;
		mlx_put_image_to_window(g->mlx, g->win, g->sprites[2], x, y);
	}
	else if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->sprites[1], x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->sprites[4], x, y);
}

void	render_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map->lines)
	{
		j = 0;
		while (j < g->map->width)
		{
			render_tile(g, g->map->map[i][j], j * 60, i * 60);
			j++;
		}
		i++;
	}
	render_player(g, g->player_x * 60, g->player_y * 60);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'C')
				count++;
	}
	return (count);
}
