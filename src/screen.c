/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:14:44 by rquilami          #+#    #+#             */
/*   Updated: 2025/05/09 10:33:58 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void put_pixel(t_core *core, int x, int y, int color)
{
    char *pixel;
    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    pixel = core->addr + (y * core->line_size + x * (core->bpp / 8));
    *(unsigned int *)pixel = color;
}
void print_window(t_core *core)
{
    int x;
    int y;

    x = 0;
    y = 0;
    core->sky = 0x87CEEB;
    core->floor = 0x228B22;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            if (y < HEIGHT / 2)
                core->color = core->sky;
            else
                core->color = core->floor;
            put_pixel(core, x, y, core->color);
            x++;
        }
        x = 0;
        y++;
    }
}
