/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:34:47 by rquilami          #+#    #+#             */
/*   Updated: 2025/05/09 13:56:05 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../mlx/mlx.h"
#include "../get_next_line/get_next_line.h"

#define RESET "\033[0m"
#define RED "\033[31m"

#define WIDTH 1200
#define HEIGHT 900
#define BLOCK 32
#define BLOCKER 32
#define MAP_WIDTH 9
#define MAP_HEIGHT 6
#define PI 3.14159265

#define W 119
#define A 97
#define S 115
#define D 100

typedef struct s_data
{
	float initAngle;
	int playerx;
	int lines_map;
	int column_map;
	int playery;
	int pos[2];
	char **map;
} t_data;

typedef struct s_player
{
	int x;
	int y;

	bool key_up;
	bool key_down;
	bool key_left;
	bool key_right;
} t_player;

typedef struct s_core
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int line_size;
	int bpp;
	int endian;
	int sky;
	int floor;
	int color;
	int px;
	int py;
	t_player player;
	t_data data;
} t_core;

void print_window(t_core *core);
void put_pixel(t_core *core, int x, int y, int color);
void vision_player(t_core *core, float initAngle);
void draw_map(t_core *core);
void ft_readmap(char *file, t_data *data);
void free_mtx(char **map);
int find_player(int *px, int *py, t_data *data);
int close_window(t_core *core);
int keyCall(int key, t_core *core);
int key_realise(int key, t_core *core);
void move_player(t_core *core);
void init_player(t_player *player);
void draw_square(int x, int y, int size, int color, t_core *core);
#endif
