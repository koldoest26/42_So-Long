/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:38 by luestira          #+#    #+#             */
/*   Updated: 2025/05/26 13:11:24 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

int	is_valid_position(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->lines)
		return (0);
	if (game->map->map[y][x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (try_move(game, new_x, new_y))
		render_map(game);
}

int	handle_cell(t_game *game, char next_cell, int new_x, int new_y)
{
	if (next_cell == '1')
		return (0);
	if (next_cell == 'C')
	{
		game->collectibles--;
		game->map->map[new_y][new_x] = '0';
	}
	if (next_cell == 'E')
	{
		if (game->collectibles == 0)
		{
			close_game(game);
			return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	try_move(t_game *game, int new_x, int new_y)
{
	char	next_cell;

	if (!is_valid_position(game, new_x, new_y))
		return (0);
	next_cell = game->map->map[new_y][new_x];
	if (!handle_cell(game, next_cell, new_x, new_y))
		return (0);
	game->map->map[game->player_y][game->player_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	printf("Total movements: %d\n", game->moves);
	return (1);
}
