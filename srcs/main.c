/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:23:50 by synicole          #+#    #+#             */
/*   Updated: 2023/04/26 14:31:26 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*prompt_output;
	t_token	*list;
	t_token	*env;

	(void)argc;
	(void)argv;
	list = NULL;
	env = NULL;
	env = env_in_list(envp, env);
	prompt_output = "";
	while (prompt_output != NULL)
	{
		ft_init_signals();
		prompt_output = readline("minishell-1.0$ ");
		if (!prompt_output)
			ft_close();
		list = split_new_format(prompt_output, list);
		list = replace_if_dollar(list, env);
		if (list)
		{
			init_type_in_list(list, env);
			if (!check_if_built(list, env))
				check_if_command(list, env);
			while (list)
			{
				printf("liste : %s\n", list->str);
				printf("type : %d\n", list->type);
				list = list->next;
			}
		}
		free_list(list);
		add_history(prompt_output);
	}
	return (0);
}
