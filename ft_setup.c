/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:10:07 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/06 17:56:23 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_test_hori(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (str[i] == '#')
			return (0);
		i++;
	}
	return (-1);
}

static int		ft_test_verti(char **tab, int j, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (tab[i][j] == '#')
			return (0);
		i++;
	}
	return (-1);
}

static void		ft_set_dim(t_data *d)
{
	int x;

	x = 0;
	while (x < 4)
	{
		if (ft_test_hori(d->tab[x], 4) == 0)
			d->j++;
		if (ft_test_verti(d->tab, x, 4) == 0)
			d->i++;
		x++;
	}
	while (ft_test_verti(d->tab, d->y, 4) == -1)
		d->y++;
	while (ft_test_hori(d->tab[d->x], 4) == -1)
		d->x++;
}

int				ft_setup(t_data *d)
{
	d->i = 0;
	d->j = 0;
	d->x = 0;
	d->y = 0;
	if (!(d->tab = ft_strsplit(d->str, '\n')))
		return (-1);
	ft_set_dim(d);
	return (0);
}
