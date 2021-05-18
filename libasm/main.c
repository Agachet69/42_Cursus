/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:25:52 by agachet           #+#    #+#             */
/*   Updated: 2021/05/06 14:11:22 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libasm.h"

int main()
{
	char *dst;
	char *c;
	int fd;
	int i;


	printf("\n\n~~~~~~~ FT_READ ~~~~~~~\n");
	i = 1;
	c = malloc(i + 1);
	fd = open("main.c", O_RDONLY);
	while (i == 1)
	{
		i = ft_read(fd, c, 1);
		printf("%s", c);
	}
	close(fd);
	printf("\n\n");
	fd = open("main.c", O_RDONLY);
	i = 1;
	while (i == 1)
	{
		i = ft_read(fd, c, 1);
		printf("%s", c);
	}
	close(fd);

	printf("\n~~~~~~~ FT_STRLEN ~~~~~~~\n");
	printf("1. %zu\n", ft_strlen("1467645646"));
	printf("1. %zu\n", strlen("1467645646"));
	printf("------------------------\n");
	printf("2. %zu\n", ft_strlen("bawgebuagvasgifudiofadgrehgkhjagdfgilurhegbvcnav[egerghbfdvbkbcvirubvdf"));
	printf("2. %zu\n", strlen("bawgebuagvasgifudiofadgrehgkhjagdfgilurhegbvcnav[egerghbfdvbkbcvirubvdf"));
	printf("------------------------\n");
	printf("3. %zu\n", ft_strlen(""));
	printf("3. %zu\n", strlen(""));

	printf("\n\n~~~~~~~ FT_STRCPY ~~~~~~~\n");
	printf("1. %s\n", strcpy(dst, "BON"));
	printf("1. %s\n", ft_strcpy(dst, "BON"));
	printf("------------------------\n");
	printf("2.%s\n", strcpy(dst, "BONwgrwwgwg853_'[;'./.[][l[pk;qq123456789-=!@#$^&()_+"));
	printf("2.%s\n", ft_strcpy(dst, "BONwgrwwgwg853_'[;'./.[][l[pk;qq123456789-=!@#$^&()_+"));
	printf("------------------------\n");
	printf("3. %s\n", ft_strcpy(dst, ""));
	printf("3. %s\n", strcpy(dst, ""));


	printf("\n\n~~~~~~~ FT_STRCMP ~~~~~~~\n");
	printf("1. %d\n", ft_strcmp("", ""));
	printf("1. %d\n", strcmp("", ""));
	printf("------------------------\n");
	printf("2. %d\n", ft_strcmp("sisisisiiii", "sisisissiii"));
	printf("2. %d\n", strcmp("sisisisiiii", "sisisissiii"));
	printf("------------------------\n");
	printf("3. %d\n", ft_strcmp("nooon", "nooon"));
	printf("3. %d\n", strcmp("nooon", "nooon"));


	printf("\n\n~~~~~~~ FT_STRDUP ~~~~~~~\n");
	dst = malloc(8);
	printf("1. %s\n", ft_strdup("eth"));
	printf("1. %s\n", strdup("eth"));
	printf("------------------------\n");
	printf("2. %s\n", ft_strdup("oahbdfiugybihdfbkrtilbhldfhbgetugblfbgerb"));
	printf("2. %s\n", strdup("oahbdfiugybihdfbkrtilbhldfhbgetugblfbgerb"));
	printf("------------------------\n");
	printf("3. %s\n", strdup(""));
	printf("3. %s\n", strdup(""));
	free (dst);

	printf("\n\n~~~~~~~ FT_WRITE ~~~~~~~\n");
	ft_write(1, "1. popopo\n", 30);
	write(1, "1. popopo\n", 30);
	write(1, "\n", 2);
	return (0);
}
