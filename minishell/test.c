/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:55:17 by agachet           #+#    #+#             */
/*   Updated: 2021/06/25 19:20:02 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

typedef struct s_test
{
	char *str;
	struct s_test *next;
}				t_test;

void	ft_lstadd_back(t_test **env, char *str)
{
	t_test	*new;
	t_test	*tmp;

	if (!(new = malloc(sizeof(new))))
		exit (EXIT_FAILURE);
	if (*env == NULL)
	{
		new->str = str;
		new->next = NULL;
		(*env) = new;
	}
	else
	{
		new->str = str;
		new->next = NULL;
		tmp = (*env);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_test	**ft_readline()
{
	char	*str;
	t_test	**test;

	*test = NULL;
	str = " ";
	while (strcmp(str, "FIN") != 0)
	{
		str = readline("> ");
		if ((strcmp(str, "FIN") != 0))
			ft_lstadd_back(test, str);
	}
	return (test);
}

void	ft_redi(t_test **test)
{
	t_test	*tmp;
	char *str;
	t_test	**res;

	tmp = *test;
	while (tmp != NULL)
	{
		if (strcmp(tmp->str, "<<") == 0)
		{
			res = ft_readline();
			while ((*res) != NULL)
			{
				printf("%s\n", (*res)->str);
				(*res) = (*res)->next;
			}
		}
		tmp = tmp->next;
	}
}

int main()
{
	t_test *test;
	char *str;

	test = NULL;
	str = NULL;
	while (1)
	{
		str = readline("test > ");
		if (str)
			add_history(str);
		ft_lstadd_back(&test, str);
		ft_redi(&test);
	}
}
