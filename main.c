/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:56:52 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/02/10 15:17:49 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cubgame.h"

/*void	close_program(void *mlx, void *mlx_win, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img); // Libere a imagem
	if (mlx_win)
		mlx_destroy_window(mlx, mlx_win); // Libere a janela
	mlx_destroy_display(mlx); // Libere o display (Linux)
	free(mlx); // Libere o ponteiro mlx
	exit(0); // Encerre o programa
}

int	handle_close(void *params)
{
	void	**data;

	data = (void **)params; // Data contém mlx, mlx_win, img
	close_program(data[0], data[1], data[2]);
	return (0);
}*/

int	main(void)
{
	int h, w;
	char *url;
	 
	t_game	game;
	init_cub3d(&game);
	h = w = 0;
	url = "./img/E.xpm";
	game.textura = mlx_xpm_file_to_image(game.mlx, url, &w, &h);
	game.data_tex = mlx_get_data_addr(game.textura, &game.bpp_tex, &game.size_line_tex, &game.endian_tex);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
