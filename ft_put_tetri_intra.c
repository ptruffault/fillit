/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tetri_intra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:49:36 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/06 17:51:21 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_tetri_in_map(t_data *d, t_map *map, t_point *pts, char c)
{
	int i;
	int j;

	i = d->x;
	while (i < d->x + d->j)
	{
		j = d->y;
		while (j < d->y + d->i)
		{
			if (d->tab[i][j] != '.')
				map->map[pts->x + i - d->x][pts->y + j - d->y] = c;
			j++;
		}
		i++;
	}
}

static int	ft_test_map(t_data *d, t_map *map, t_point *pts)
{
	int i;
	int j;

	i = d->x;
	while (i < d->x + d->j)
	{
		j = d->y;
		while (j < d->y + d->i)
		{
			if (map->map[pts->x + i - d->x][pts->y + j - d->y] != '.'
			&& d->tab[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_tetri_in_map(d, map, pts, d->chara);
	return (1);
}

void		ft_sort(t_map *map, t_data *d)
{
	t_point pts;

	pts.x = 0;
	while (pts.x < map->len - d->j + 1 && map->best == 0)
	{
		pts.y = 0;
		while (pts.y < map->len - d->i + 1 && map->best == 0)
		{
			if (ft_test_map(d, map, &pts) == 1)
			{
				if (!(d->next))
				{
					map->best = 1;
					ft_put_map(map);
				}
				else
				{
					ft_sort(map, d->next);
					ft_tetri_in_map(d, map, &pts, '.');
				}
			}
			pts.y++;
		}
		pts.x++;
	}
}
