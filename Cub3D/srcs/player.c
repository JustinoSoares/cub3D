/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:18:36 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/02/03 14:42:13 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubgame.h"

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;

	player->key_up = false;
	player->key_right = false;
	player->key_down = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate =  false;
}

int	key_press(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	else if (keycode == D)
		player->key_right = false;
	else if (keycode == S)
		player->key_down = false;
	else if (keycode == A)
		player->key_left = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void	move_player(t_game *game, t_player *player)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;
	float	new_x;
	float	new_y;


	speed = 3;
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);

	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;

	new_x = player->x;
	new_y = player->y;
	if (player->key_up)
	{
		new_x += cos_angle * speed;
		new_y += sin_angle * speed;
	}
	if (player->key_down)
	{
		new_x -= cos_angle * speed;
		new_y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		new_x += sin_angle * speed;
		new_y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		new_x -= sin_angle * speed;
		new_y += cos_angle * speed;
	}
	if (!touch(game, new_x, player->y))
		player->x = new_x;
	if (!touch(game, player->x, new_y))
		player->y = new_y;
}
