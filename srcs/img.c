/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:03:33 by amdos-sa          #+#    #+#             */
/*   Updated: 2025/02/10 12:54:33 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubgame.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

int	get_pixel(t_game *game, int x, int y)
{
	int	index;
	int	color;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return (0); // Retorna preto se o pixel estiver fora dos limites
	
	index = y * game->size_line_tex + x  * game->bpp_tex / 8;
	color = (game->data_tex[index] & 0xFF) | 
			((game->data_tex[index + 1] & 0xFF) << 8) | 
			((game->data_tex[index + 2] & 0xFF) << 16);
	//printf("%d\n", y);
	return (color);
}


void	clear_image(t_game *game)
{
	int	y;
	int	x;
	int color = 0x2BEAFF;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(game, x, y, color);
			x++;
		}
		if (y == HEIGHT / 2)
		{
			color = 0x2BFF86;
		}
		y++;
	}
}
