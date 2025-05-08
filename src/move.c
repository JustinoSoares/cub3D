/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:36:05 by rquilami          #+#    #+#             */
/*   Updated: 2025/05/08 16:11:12 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void clear_image(t_core *core, int color)
{
    int x, y;
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            put_pixel(core, x, y, color);
        }
    }
}

int close_window(t_core *core)
{
    (void)core;
    // mlx_destroy_window(core->mlx, core->win);
    // mlx_destroy_image(core->mlx, core->img);
    // mlx_destroy_display(core->mlx);
    // free_mtx(core->data.map);
    exit(0);
    return (0);
}

int keyCall(int key, t_core *core)
{
    if (key == 65307) // ESC
        close_window(core);

    if (key == 119) // W - move pra frente
    {
        core->px -= 1.0;
        core->py -= 1.0;
        printf("clicou em w\n");
    }

    if (key == 115) // S - move pra trás
    {
        core->px += 1.0;
        core->py += 1.0;
        printf("clicou em s\n");
    }

    if (key == 100) // D - rotaciona para direita
    {
        printf("clicou em d\n");
        core->data.initAngle += 5;
        if (core->data.initAngle >= 360)
            core->data.initAngle -= 360;
    }

    if (key == 97) // A - rotaciona para esquerda
    {
        printf("clicou em a\n");
        core->data.initAngle -= 5;
        if (core->data.initAngle < 0)
            core->data.initAngle += 360;
    }

    if (key == 65361) // seta esquerda - mesma ação do 'a'
    {
        printf("clicou em <\n");
        core->data.initAngle -= 5;
        if (core->data.initAngle < 0)
            core->data.initAngle += 360;
    }

    if (key == 65363) // seta direita - mesma ação do 'd'
    {
        printf("clicou em >\n");
        core->data.initAngle += 5;
        if (core->data.initAngle >= 360)
            core->data.initAngle -= 360;
    }

    // 💥 limpa a imagem (cor de fundo: preto, ou outro se quiser)
    //clear_image(core, 0x000000);
    print_window(core);
    // redesenha tudo com estado atualizado
    vision_player(core, core->data.initAngle);
    draw_map(core);
    mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
    return (0);
}
