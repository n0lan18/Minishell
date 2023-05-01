/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:23:50 by synicole          #+#    #+#             */
/*   Updated: 2023/04/29 01:57:37 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_last_exit_code;

int	main(int argc, char **argv, char **envp)
{
	char	*prompt_output;
	char	**arg_input;
	t_token	*list;
	t_token	*env;
	int		i;

	list = NULL;
	env = NULL;
	env = env_in_list(envp, env);
	prompt_output = "";
	g_last_exit_code = 0;
	if (argc == 3 && ft_strncmp(argv[1], "-c", 3) == 0 && argv[2])
	{
		arg_input = ft_split(argv[2], ';');
		if (!arg_input)
			ft_close();
		i = 0;
		while (arg_input[i])
		{
			if (!arg_input[i])
				ft_close();
			list = split_new_format(arg_input[i], list);
			list = good_parse(list, env);
			if (list)
			{
				ft_assign_type_for_each_token(list);
				if (!check_if_built(list, env))
					check_if_command(list, env);
				while (list)
					list = list->next;
			}
			free_list(list);
			i++;
		}
	}
	else
	{
		while (prompt_output != NULL)
		{
			ft_init_signals();
			prompt_output = readline("minishell-1.0$ ");
			if (!prompt_output)
				ft_close();
			list = split_new_format(prompt_output, list);
//			list = good_parse(list, env);
			if (list)
			{
				ft_assign_type_for_each_token(list);
//				if (!check_if_built(list, env))
//					check_if_command(list, env);
				while (list)
				{
					printf("(TOKEN)[%s] -> (TYPE)[%d]\n", list->str, list->type);
					list = list->next;
				}
			}
			free_list(list);
			add_history(prompt_output);
		}
	}
	return (0);
}
