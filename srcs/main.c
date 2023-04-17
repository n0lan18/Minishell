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
	char	*prompt_output;
	t_token	*list;

	(void)argc;
	(void)argv;
	list = NULL;
	prompt_output = "";
	while (prompt_output != NULL)
	{
		ft_init_signals();
		prompt_output = readline("minishell-1.0$ ");
		list = split_new_format(prompt_output, list);
		list = replace_if_dollar(list, envp);
		while (list)
		{
			printf("LISTE %s\n", list->str);
			list = list->next;
		}
		free_list(list);
		add_history(prompt_output);
	}
	ft_close();
	return (0);
}
