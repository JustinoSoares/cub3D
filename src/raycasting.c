/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:19:17 by rquilami          #+#    #+#             */
/*   Updated: 2025/05/11 00:35:25 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"


void draw_map(t_core *core)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int j;
    while (y < core->data.lines_map)
    {   
        x = 0;
        while (x < core->data.column_map)
        {
            if (core->data.map[y][x] == '1')
            {
                i = 0;
                while (i < BLOCK)
                {
                    j = 0;
                    while (j < BLOCK)
                    {
                        draw_square(x * BLOCKER, y * BLOCKER, BLOCKER, 0xff00ff, core);
                        //put_pixel(core, x * BLOCK + j, y * BLOCK + i, 0xFFFFFF);
                        j++;
                    }
                    i++;
                }
            }
            x++;
        }
        y++;
    }
}


void dda(float angle, t_core *core)
{
    float angleRad = angle * PI / 180.0;
    float dx = cos(angleRad);
    float dy = sin(angleRad);
    
    float x = core->player.x + 0.5f;
    float y = core->player.y + 0.5f;
    while (1)
    {
        int px = (int)x;
        int py = (int)y;
        if (px < 0 || px >= core->data.column_map || py < 0 || py >= core->data.lines_map)
            break;
        if (core->data.map[py][px] == '1')
            break;
        int screenX = (int)(x * BLOCK);
        int screenY = (int)(y * BLOCK);
        put_pixel(core, screenX, screenY, 0x00FF0000);
        x += dx * 0.1f;
        y += dy * 0.1f;
    }
}

void vision_player(t_core *core, float initAngle)
{
    find_player(&core->data);
    float angle;
    angle = initAngle - 0;
    while (angle <= initAngle + 0)
    {
        dda(angle, core);
        angle += 0.1f;
    }
}

