/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:56:52 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/02/03 09:03:27 by amdos-sa         ###   ########.fr       */
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
	t_game	game;

	init_cub3d(&game);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
