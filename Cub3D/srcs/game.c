/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:57:59 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/02/03 14:39:16 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubgame.h"

void	init_cub3d(t_game *game)
{
	init_player(&game->player);
	game->map = get_map();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(game, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, x + size, y + i, color);
			i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, x + i, y + size, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(game, x, y + i, color);
		i++;
	}
}

bool	touch(t_game *game, float px, float py)
{
	int	x;
	int	y;

	x = px / SBLOCK;
	y = py / SBLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(t_game *game, float x1, float y1, float x2, float y2)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	draw_line(t_game *game, t_player *player, float start_x, int i)
{
	float		ray_x;
	float		ray_y;
	float		cos_angle;
	float		sin_angle;
	float		dist;
	float		height;
	float		start_y;
	int			end;
	ray_x = player->x;
	ray_y = player->y;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	while (!touch(game, ray_x, ray_y))
	{
		if (DEBUG)
			put_pixel(game, ray_x, ray_y, 0xADD8E6);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	if (!DEBUG)
	{
		dist = fixed_dist(game, player->x, player->y, ray_x, ray_y);
		height = (SBLOCK / dist) * (WIDTH / 2);
		start_y = (HEIGHT - height) / 2;
		end = start_y + height;
		while (start_y < end)
		{
			put_pixel(game, i, start_y, 0xADD8E6);
			start_y++;
		}
	}
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	i = 0;
	player = &game->player;
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6;
	move_player(game, player);
	clear_image(game);
	if (DEBUG)
	{
		draw_square(game, player->x, player->y, 10, 0x39FF14);
		draw_map(game);
	}
	while (i < WIDTH)
	{
		draw_line(game, player, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
