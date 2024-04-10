/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:36:14 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 17:43:52 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "mlx.h"
#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *) b + i) = c;
		i++;
	}
	return (b);
}

int	exit_game(t_complete *game)
{
	int	line;

	line = 0;
	if (game->window)
		mlx_destroy_window(game->mlx_pointer, game->window);
	free(game->mlx_pointer);
	while (line <= game->heightmap -1)
	{
		free(game->map[line++]);
	}
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	if (!ft_strchr(argv[1], '.ber'))
	{
		ft_printf("Not type .ber file");
		exit (0);
	}
	ft_memset(&game, 0, sizeof(t_complete));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlx_pointer = mlx_init();
	game.window = mlx_new_window(game.mlx_pointer, (game.widthmap * 40),
			(game.heightmap * 40), "solong");
	return (0);
}
