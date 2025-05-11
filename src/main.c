/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:41:46 by rquilami          #+#    #+#             */
/*   Updated: 2025/05/11 02:21:38 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

void init_config(t_core *core)
{
    core->mlx = mlx_init();
    core->win = mlx_new_window(core->mlx, WIDTH, HEIGHT, "cub3d");
    core->img = mlx_new_image(core->mlx, WIDTH, HEIGHT);
    core->addr = mlx_get_data_addr(core->img, &core->bpp, &core->line_size, &core->endian);
    core->px = 0;
    core->py = 0;
}

void draw_square(int x, int y, int size, int color, t_core *core)
{
    // Proteção contra desenhar fora da janela
    if (x < 0 || y < 0 || x + size >= WIDTH || y + size >= HEIGHT)
        return;
    for (int i = 0; i < size; i++)
        put_pixel(core, x + i, y, color); // topo
    for (int i = 0; i < size; i++)
        put_pixel(core, x, y + i, color); // esquerda
    for (int i = 0; i < size; i++)
        put_pixel(core, x + size, y + i, color); // direita
    for (int i = 0; i < size; i++)
        put_pixel(core, x + i, y + size, color); // base
}
void clear_images(t_core *core)
{
    for (int y = 0; y < HEIGHT; y++)
        for(int x = 0; x < WIDTH; x++)
            put_pixel(core, x, y, 0);
}
int draw_loop(void *param)
{
    t_core *core = (t_core *)param;
    t_player *player = &core->player;
    move_player(core);
    clear_images(core);
    //print_window(core);
    //printf("ponto x %d y %d\n", player->x, player->y);
    draw_map(core);
    draw_square(player->x * BLOCKER, player->y * BLOCKER, 10, 0x00ffff, core);
    vision_player(core, core->data.initAngle);
    mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return -1;
    t_core *core = calloc(1, sizeof(t_core));

    init_config(core);
    core->data.initAngle = 0;
    ft_readmap(argv[1], &core->data);
    //draw_square(WIDTH / 2, HEIGHT / 2, 10, 0x00ffff, core);
    init_player(&core->player, &core->data);
    //print_window(core);
    //draw_map(core);
    vision_player(core, core->data.initAngle);
    mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
    mlx_hook(core->win, 17, 0, close_window, core);
    mlx_hook(core->win, 2, 1L << 0, keyCall, core);
    mlx_hook(core->win, 3, 1L << 0, key_realise, core);
    mlx_loop_hook(core->mlx, draw_loop, core);
    mlx_loop(core->mlx);
    return (0);
}