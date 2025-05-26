/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:14:03 by luestira          #+#    #+#             */
/*   Updated: 2025/05/26 15:27:42 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		lines;
	int		width;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*sprites[5];
	t_map	*map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}	t_game;

int		check_args(int argc, char **argv);
int		counter_lines(char **argv);
char	**save_map(int lines, char **argv);
int		check_lines_length(int lines, char **map);
int		check_walls(int lines, char **map);
int		check_positions(int lines, char **map);
int		count_line_map(char *line, int *e, int *p, int *c);
int		valid_char(int lines, char **map);
char	**dup_map(char **map, int lines);
void	find_player(char **map, int *y, int *x);
void	flood_fill(char **map, int y, int x, int lines);
int		path_is_valid(char **map, int lines);
int		check_path(int lines, char **map);
void	free_map(char **map, int lines);
int		checking_main_utils(int lines, char **map);
void	start_game(char **map, int lines, int cols);
void	render_map(t_game *g);
void	render_tile(t_game *g, char tile, int x, int y);
int		count_collectibles(char **map);
int		close_game(t_game *game);
int		handle_exit(int keycode, t_game *game);
int		start_game_checker(t_game *g, t_map *map_data);
int		is_valid_position(t_game *game, int x, int y);
void	move_player(t_game *game, int dx, int dy);
int		handle_cell(t_game *game, char next_cell, int new_x, int new_y);
int		try_move(t_game *game, int new_x, int new_y);
int		handle_key(int keycode, t_game *game);
void	render_player(t_game *g, int x, int y);

#endif
