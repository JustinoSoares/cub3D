/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 08:33:53 by jsoares           #+#    #+#             */
/*   Updated: 2025/05/11 02:22:08 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void init_player(t_player *player, t_data *data)
{
    find_player(data);
    player->x = data->x;
    player->y = data->y;

    player->angle = PI / 2;

    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;

    player->key_rot_left = false;
    player->key_rot_right = false;
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

// Verifica se pode andar para a posição (x, y)
int can_move_to(t_core *core, float x, float y)
{
    int map_x = (int)(x / BLOCK);
    int map_y = (int)(y / BLOCK);

    // Evita andar fora dos limites
    if (map_y < 0 || map_y >= core->data.lines_map || map_x < 0 || map_x >= core->data.column_map)
        return 0;

    // Verifica se não é parede
    return (core->data.map[map_y][map_x] != '1');
}

int collision(t_core *core, float x, float y)
{
    if (core->data.map[(int)x][(int)y] == '0')
    {
        printf("coli %c\n", core->data.map[(int)x][(int)y]);
        return 1;
    }
    return 0;
}

void move_player(t_core *core)
{
    float speed = 0.5f;
    float angle = core->data.initAngle;
    //float angle_speed = 0.1f;
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);

    if (core->player.key_rot_left)
        core->player.angle -= 0.1f;
    if (core->player.key_rot_right)
        core->player.angle += 0.1f;
    if (core->player.angle > PI * 2)
        core->player.angle = 0;
    if (core->player.angle < 0)
        core->player.angle = PI * 2;

    // Move para frente/para trás conforme o ângulo
    if (core->player.key_up)
    {
        core->player.x += cos_angle * speed;
        core->player.y += sin_angle * speed;
    }
    if (core->player.key_down)
    {
        core->player.x -= cos_angle * speed;
        core->player.y -= sin_angle * speed;
    }

    // Strafe (movimento lateral)
    if (core->player.key_left)
    {
        core->player.x += cos_angle * speed;
        core->player.y -= sin_angle * speed;
    }
    if (core->player.key_right)
    {
        core->player.x -= cos_angle * speed;
        core->player.y += sin_angle * speed;
    }

    realise_moves(core);
}
