/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:51:39 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 17:41:13 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct t_start
{
	int		fd;
	char	t_line;
	int		widthmap;
	int		heightmap;
	int		coleccionables;
	int		player;
	int		exit;

	char	**map;

	void	*mlx_pointer;
	void	*window;

}	t_complete;
int		map_reading(t_complete *game, char **argv);
char	*ft_sstrdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	check_errors(t_complete *game);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_sstrlen(const char *str);
void	check_player(t_complete *game);
int		exit_game(t_complete *game);

#endif
