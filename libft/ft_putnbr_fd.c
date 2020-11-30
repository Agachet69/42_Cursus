/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:22:13 by agachet           #+#    #+#             */
/*   Updated: 2020/11/27 16:07:40 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharf(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putcharf('-', fd);
			n = n * -1;
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putcharf(((n % 10) + 48), fd);
		}
		else
		{
			ft_putcharf((n + 48), fd);
		}
	}
}
