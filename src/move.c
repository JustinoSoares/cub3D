/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:36:05 by rquilami          #+#    #+#             */
/*   Updated: 2025/05/11 02:25:50 by justinosoar      ###   ########.fr       */
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
    if (key == W) // W - move pra frente
    {
        printf("clicou em w\n");
        core->player.key_up = true;
    }
    if (key == S) // S - move pra trás
    {
        core->player.key_down = true;
        printf("clicou em s\n");
    }

    if (key == D) // D - rotaciona para direita
    {
        printf("clicou em d\n");
        core->player.key_right = true;
    }

    if (key == A) // A - rotaciona para esquerda
    {
        core->player.key_left = true;
        printf("clicou em a\n");
    }

    if (key == LEFT) // seta esquerda - mesma ação do 'a'
    {
        printf("clicou em <\n");
        core->data.initAngle -= 0.1f;
        if (core->data.initAngle < 0)
             core->data.initAngle += 360;
        core->player.key_rot_left = true;
    }

    if (key == RIGHT) // seta direita - mesma ação do 'd'
    {
        printf("clicou em >\n");
        core->player.key_rot_right = true;
         core->data.initAngle += 0.1f;
         if (core->data.initAngle >= 360)
             core->data.initAngle -= 360;
    }

    // 💥 limpa a imagem (cor de fundo: preto, ou outro se quiser)
    //clear_image(core, 0x000000);
    /* print_window(core);
    vision_player(core, core->data.initAngle);
    // redesenha tudo com estado atualizado
    draw_map(core);
    mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);*/
    //draw_square(WIDTH / 2, HEIGHT / 2, 10, 0x00ffff, core);
    return (0);
}

int key_realise(int key, t_core *core)
{
    if (key == W) // W - move pra frente
    {
        printf("release em w\n");
        core->player.key_up = false;
    }

    if (key == S) // S - move pra trás
    {
        core->player.key_down = false;
        printf("release em s\n");
    }

    if (key == D) // D - rotaciona para direita
    {
        printf("release em d\n");
        core->player.key_left = false;
    }

    if (key == A) // A - rotaciona para esquerda
    {
        core->player.key_right = false;
        printf("release em a\n");
    }
    if (key == LEFT) // seta esquerda - mesma ação do 'a'
    {
        printf("realise em <\n");
        core->player.key_rot_left = false;
    }

    if (key == RIGHT) // seta direita - mesma ação do 'd'
    {
        printf("relise em >\n");
        core->player.key_rot_right = false;
        // core->data.initAngle += 5;
        // if (core->data.initAngle >= 360)
        //     core->data.initAngle -= 360;
    }
    return 0;
}
