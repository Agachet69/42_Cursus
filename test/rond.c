/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:30:39 by agachet           #+#    #+#             */
/*   Updated: 2021/11/18 19:30:43 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct		s_zone
{
	int			width;
	int			height;
	char		background;
	char		**array;
}					t_zone;

typedef struct		s_draw
{
	char		render;
	float		x;
	float		y;
	float		radius;
	char		trace;
}					t_draw;

int		ft_error(const char *str)
{
	int		i;

	i = -1;
	while (str && str[++i])
		write(1, &str[i], 1);
	return (EXIT_FAILURE);
}

int		set_zone(t_zone *paper)
{
	int		x;
	int		y;

	if ((paper->array = malloc(sizeof(char *) * (paper->height + 1))) == NULL)
		return (EXIT_FAILURE);
	y = -1;
	while (++y < paper->height)
	{
		if ((paper->array[y] = malloc(sizeof(char) * (paper->width + 1))) == NULL)
			return (EXIT_FAILURE);
		x = -1;
		while (++x < paper->width)
			paper->array[y][x] = paper->background;
		paper->array[y][x] = '\0';
	}
	paper->array[y] = NULL;
	return (EXIT_SUCCESS);
}

void	print_paper(t_zone paper)
{
	int		x;
	int		y;

	y = -1;
	while (paper.array[++y])
	{
		x = -1;
		while (paper.array[y][++x])
			write(1, &paper.array[y][x], 1);
		write(1, "\n", 1);
	}
}

int		is_good(float x, float y, t_draw pencil)
{
	float	limit;
	float	dist;

	limit = 1.00000000;
	dist = sqrtf(((x - pencil.x) * (x - pencil.x)) + ((y - pencil.y) * (y - pencil.y)));

	if (dist <= pencil.radius)
	{
		if (pencil.radius - dist < limit)
			return (2);
		return (1);
	}
	return (0);
}

void	go_to_draw(t_zone paper, t_draw pencil)
{
	int		x;
	int		y;
	float	good;

	y = -1;
	while (++y < paper.height)
	{
		x = -1;
		while (++x < paper.width)
		{
			good = is_good((float)x, (float)y, pencil);
			if ((pencil.render == 'c' && good == 2) || (pencil.render == 'C' && good > 0))
				paper.array[y][x] = pencil.trace;
		}
	}
}

int		main(int argc, char **argv)
{
	FILE	*fd;
	t_zone	paper;
	t_draw	pencil;
	int		i;
	int		ret;

	(void)pencil;

	if (argc != 2)
		return (ft_error("Error: Argument\n"));
	if ((fd = fopen(argv[1], "r")) == NULL)
		return (ft_error("Error: Operation file corrupted\n"));
	ret = 0;
	if ((ret = fscanf(fd, "%d %d %c\n", &paper.width, &paper.height, &paper.background)) != 3)
		return (ft_error("Error: Operation file corrupted\n"));
	if ((paper.width < 1 || paper.width > 300) || (paper.height < 1 || paper.height > 300))
		return (ft_error("Error: Operation file corrupted\n"));
	if (set_zone(&paper) == EXIT_FAILURE)
		return (ft_error("Error: Malloc Failed\n"));
	ret = 0;
	while ((ret = fscanf(fd, "%c %f %f %f %c\n", &pencil.render, &pencil.x, &pencil.y, &pencil.radius, &pencil.trace)) == 5)
	{
		if ((pencil.render != 'c' && pencil.render != 'C') || pencil.radius <= 0.00000000)
			break ;
		go_to_draw(paper, pencil);
	}
	if (ret == -1)
		print_paper(paper);
	if (paper.array != NULL)
	{
		i = -1;
		while (paper.array[++i])
			free(paper.array[i]);
		free(paper.array);
	}
	if (fd != NULL)
		fclose(fd);
	if (ret != -1)
		return (ft_error("Error: Operation file corrupted\n"));
	return (EXIT_SUCCESS);
}
