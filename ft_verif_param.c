/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:53:32 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/06 17:54:30 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_test_arround(t_data *d, int i, int j)
{
	int c;

	c = 0;
	if (j != 0 && d->tab[i][j - 1] == '#')
		c++;
	if (j != 3 && d->tab[i][j + 1] == '#')
		c++;
	if (i != 0 && d->tab[i - 1][j] == '#')
		c++;
	if (i != 3 && d->tab[i + 1][j] == '#')
		c++;
	return (c);
}

static int	ft_verif_tetri(t_data *d)
{
	size_t	x;
	size_t	y;
	int		contact;

	contact = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (d->tab[x][y] == '#')
				contact = contact + ft_test_arround(d, x, y);
			y++;
		}
		x++;
	}
	if (contact < 6)
		return (-1);
	return (0);
}

static int	ft_verif_file(char *str)
{
	int i;
	int j;
	int c;

	c = 0;
	i = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
		j = 0;
		while (j <= 3)
		{
			if (str[i] != '.' && str[i] != '#')
				return (-1);
			if (str[i] == '#')
				c++;
			i++;
			j++;
		}
		if (str[i++] != '\n')
			return (-1);
	}
	if (c != 4)
		return (-1);
	return (0);
}

int			ft_verif_param(t_data *data, int argc, char **argv)
{
	int		ret;
	int		fd;
	char	a;

	a = 'A';
	if (argc != 2 || !(fd = open(argv[1], O_RDONLY)))
	{
		ft_putstr("error\n");
		return (-1);
	}
	while ((ret = read(fd, data->str, BUFF_SIZE)))
	{
		data->str[ret] = '\0';
		if ((ret != 20 && ret != 21) || ft_verif_file(data->str) == -1
		|| ft_setup(data) == -1 || ft_verif_tetri(data) == -1
		|| ft_add_data(data) != 0)
		{
			ft_putstr("error\n");
			return (-1);
		}
		data->chara = a++;
		data = data->next;
	}
	close(fd);
	return (0);
}
