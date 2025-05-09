/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:33:53 by jsoares           #+#    #+#             */
/*   Updated: 2025/05/09 11:36:53 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void init_player(t_player *player)
{
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;

    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;
}
static void realise_moves(t_core *core)
{
    if (core->player.key_up)
        core->player.key_up = false;
    if (core->player.key_down)
        core->player.key_down = false;
    if (core->player.key_left)
        core->player.key_left = false;
    if (core->player.key_right)
        core->player.key_right = false;
}

void move_player(t_core *core)
{

    int speed = 10;
    if (core->player.key_up && core->player.y - 5 >= 0)
        core->player.y -= speed;
    if (core->player.key_down && core->player.y <= HEIGHT - 15)
        core->player.y += speed;
    if (core->player.key_left && core->player.x - 5 >= 0)
        core->player.x -= speed;
    if (core->player.key_right && core->player.x <= WIDTH - 15)
        core->player.x += speed;
    realise_moves(core);
}
