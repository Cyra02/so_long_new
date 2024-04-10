/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:53:00 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 17:37:47 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

static int	horizontal(t_complete *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->heightmap -1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	vertical(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	check_elements(t_complete *game, int hi, int wid)
{
	if (game->map[hi][wid] != '1' &&
		game->map[hi][wid] != 'P' &&
		game->map[hi][wid] != 'E' &&
		game->map[hi][wid] != 'C' &&
		game->map[hi][wid] != '\n' )
	{
		ft_printf("falta algo aqui", game->map[hi][wid]);
		exit_game(game);
	}
	if (game->map[hi][wid] == 'C')
		game->coleccionables++;
	if (game->map[hi][wid] == 'P')
		game->player++;
	if (game->map[hi][wid] == 'E')
		game->exit++;
}

void	check_player(t_complete *game)
{
	int	hi;
	int	wid;

	hi = 0;
	while (hi < game->heightmap - 1)
	{
		wid = 0;
		while (wid <= game->widthmap)
		{
			check_elements(game, hi, wid);
			wid++;
		}
		hi++;
	}
	if (game->coleccionables >= 1
		&& game->player == 1
		&& game->exit == 1)
	{
		ft_printf("algo falta en el mapa");
		exit_game(game);
	}
}

void	check_errors(t_complete *game)
{
	int	vvertical;
	int	hhorizontal;

	vvertical = vertical(game);
	hhorizontal = horizontal(game);
	if (!vvertical || !hhorizontal)
		write(1, "mal no hay paredes tu madre", 27);
	check_player(game);
}
