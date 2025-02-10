/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubgame.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:57:02 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/02/10 16:31:29 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBGAME_H
# define CUBGAME_H

# define WIDTH 1280
# define HEIGHT 720
# define SBLOCK 54
# define DEBUG 1

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	bool		key_up;
	bool		key_right;
	bool		key_down;
	bool		key_left;
	bool		left_rotate;
	bool		right_rotate;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
	char		**map;

	int			bpp_tex;
	int			size_line_tex;
	int			endian_tex;
	char		*data_tex;
	void		*textura;
}				t_game;

typedef struct s_line
{
	int x;     // the x coordinate of line relative to screen
	int y;     // the current pixel index of the line (along y axis)
	int y0;    // y start index of drawing texture
	int y1;    // y end index of drawing texture
	int tex_x; // x coordinate of texture to draw
	int tex_y; // y coordinate of texture to draw
}				t_line;

void			init_cub3d(t_game *game);
void			draw_square(t_game *game, int x, int y, int size, int color);
void			put_pixel(t_game *game, int x, int y, int color);
int				get_pixel(t_game *game, int x, int y);
void			clear_image(t_game *game);
int				draw_loop(t_game *game);
void			init_player(t_player *player);
int				key_press(int keycode, t_player *player);
int				key_release(int keycode, t_player *player);
void			move_player(t_game *game, t_player *player);
void			draw_map(t_game *game);
char			**get_map(void);
bool			touch(t_game *game, float px, float py);

#endif
