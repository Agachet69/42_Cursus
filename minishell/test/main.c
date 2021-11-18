/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:42:03 by agachet           #+#    #+#             */
/*   Updated: 2021/06/24 18:35:24 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>

char    *get_line()
{
    char *line;

    line = NULL;
    if (line)
    {
        free(line);
        line = NULL;
    }
    line = readline("Minishell>");
    if (line)
        add_history(line);
    return (line);
}

int main(void)
{
    char    *line;

	//line = readline("Minishell>");
 //   signal(SIGINT, sig_handler);
  while (1)
	line = get_line();
    printf("%s\n", line);
}
