/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:15:18 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/06 18:10:53 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFF_SIZE 21

typedef struct	s_data
{
	char			**tab;
	char			str[BUFF_SIZE];
	int				x;
	int				y;
	int				i;
	int				j;
	char			chara;
	struct s_data	*next;
}				t_data;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;
typedef struct	s_map
{
	char	**map;
	int		len;
	int		best;
}				t_map;

void			ft_put_map(t_map *map);
int				ft_max(int a, int b);
void			ft_sort(t_map *map, t_data *data);
char			**ft_new_map(int len);
int				ft_setup(t_data *data);
int				ft_verif_param(t_data *data, int argc, char **argv);
int				ft_add_data(t_data *d);
#endif
