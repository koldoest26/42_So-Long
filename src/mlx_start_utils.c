/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:35:59 by luestira          #+#    #+#             */
/*   Updated: 2025/05/26 13:20:38 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	start_game_checker(t_game *g, t_map *map_data)
{
	if (!g)
		return (1);
	if (!map_data)
		return (free(g), 1);
	return (0);
}

void	render_player(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->sprites[2], x, y);
}
