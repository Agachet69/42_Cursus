/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:54:21 by agachet           #+#    #+#             */
/*   Updated: 2021/11/18 19:14:04 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_back
{
	int		w_back;
	int		h_back;
	char	c_back;
	char	**paint;
}				t_back;

typedef struct	s_rect
{
	char	r_char;
	float	hor_rect;
	float	ver_rect;
	float	w_rect;
	float	h_rect;
	char	paint_c;
}				t_rect;


int err_arg()
{
	write(1, "Error: argument\n", 16);
	return (1);
}

int err_file()
{
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

int	ft_malloc_paint(t_back *back)
{
	int x;
	int y;

	if ((back->paint = malloc(sizeof(char *) * (back->h_back + 1))) == NULL)
		return (1);
	y = -1;
	while (++y < back->h_back)
	{
		if ((back->paint[y] = malloc(sizeof(char) * (back->w_back + 1))) == NULL)
		{
			free (back->paint);
			return (1);
		}
		x = -1;
		while (++x < back->w_back)
			back->paint[y][x] = back->c_back;
		back->paint[y][x] = '\0';
	}
	back->paint[y] = NULL;
	return (0);
}

int	ft_good(int x, int y, t_rect rect)
{
	float limit;
	float dist;

	if (x < rect.hor_rect || x > rect.hor_rect + rect.w_rect || y < rect.ver_rect || y > rect.ver_rect + rect.h_rect)
		return (0);
	limit = 1.0000000;
	if (x - rect.h_rect < limit || rect.w_rect + rect.hor_rect - x < limit || y - rect.ver_rect < limit || rect.ver_rect + rect.h_rect - y < limit)
		return (2);
	return (1);
}

void	ft_do(t_back *back, t_rect rect)
{
	int good;
	int x;
	int y;

	y = -1;
	while (++y < back->h_back)
	{
		x = -1;
		while (++x < back->w_back)
		{
			good = ft_good(x, y, rect);
			if ((rect.r_char = 'r' && good == 2) || (rect.r_char == 'R' && good > 0))
				back->paint[y][x] = rect.paint_c;
		}
	}
}

int	ft_close(t_back back)
{
	int y;

	y = -1;
	while (++y < back.h_back)
		free(back.paint[y]);
	free(back.paint);
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

void	ft_paint(t_back back)
{
	int x;
	int y;

	y = 0;
	while (back.paint[y])
	{
		x = -1;
		while (back.paint[y][++x])
			write(1, &back.paint[y][x], 1);
		write(1, "\n", 1);
		y++;
	}
	y = -1;
	while (++y < back.h_back)
		free(back.paint[y]);
	free(back.paint);
}

int main(int ac, char **av)
{
	t_back back;
	t_rect rect;
	FILE *fd;
	int num;


	if (ac != 2)
		return (err_arg());
	if ((fd = fopen(av[1], "r")) == NULL)
		return (err_file());
	if (fscanf(fd, "%d %d %c\n" , &back.w_back, &back.h_back, &back.c_back) != 3)
		return (err_file());
	if (back.w_back < 1 || back.w_back > 300 || back.h_back < 1 || back.h_back > 300)
		return (err_file());
	if (ft_malloc_paint(&back) == 1)
		return (err_file());
	while ((num = fscanf(fd, "%c %f %f %f %f %c\n", &rect.r_char, &rect.hor_rect, &rect.ver_rect, &rect.w_rect, &rect.h_rect, &rect.paint_c)) == 6)
	{
		if (rect.w_rect <= 0.0000 || rect.h_rect <= 0.0000)
			break;
		ft_do(&back, rect);
	}
	if (fd != NULL)
		fclose(fd);
	if (num != -1)
		return (ft_close(back));
	ft_paint(back);
	return (0);
}
