/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:54:29 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/06 16:29:37 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_smart_search(t_data *d, int len)
{
	int		i;
	t_data	*tmp;

	tmp = d;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (i * 4 <= len * len)
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (ft_verif_param(&data, argc, argv) == -1)
		return (-1);
	map.len = ft_max(data.i, data.j) - 1;
	map.best = 0;
	while (map.best == 0)
	{
		map.map = ft_new_map(++map.len);
		if (ft_smart_search(&data, map.len) == 1)
			ft_sort(&map, &data);
		free(map.map);
	}
	return (0);
}
