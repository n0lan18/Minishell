/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:23:50 by synicole          #+#    #+#             */
/*   Updated: 2023/04/10 11:23:53 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*rl;
	t_list	*list;

	(void) envp;
	if (argc == 1)
	{
		list = NULL;
		rl = "0";
		while (ft_strncmp(rl, "exit", ft_strlen(rl)) != 0)
		{
			list = NULL;
			rl = readline("minishell-1.0$ ");
			list = split_new_format(rl, list);
			list = replace_if_dollar(list, envp);
			while (list)
			{
				printf("LISTE %s\n", list->str);
				list = list->next;
			}
		}
		return (0);
	}
	perror(argv[1]);
	return (0);
}
