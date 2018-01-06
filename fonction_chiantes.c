/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_chiantes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:38:55 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/06 17:49:15 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_add_data(t_data *src)
{
	t_data *new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	new->next = NULL;
	src->next = new;
	return (0);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_put_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->len)
	{
		j = 0;
		while (j < map->len)
			ft_putchar(map->map[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

char	**ft_new_map(int len)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	while (i < len)
	{
		if (!(new[i] = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		j = 0;
		while (j < len)
		{
			new[i][j] = '.';
			j++;
		}
		i++;
	}
	return (new);
}
