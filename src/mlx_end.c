/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:06:28 by luestira          #+#    #+#             */
/*   Updated: 2025/05/21 14:44:10 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(t_game *game)
{
	if (game->map)
	{
		free_map(game->map->map, game->map->lines);
		free(game->map);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	exit (0);
	return (0);
}

int	handle_exit(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	return (0);
}
