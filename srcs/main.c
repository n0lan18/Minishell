/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:23:50 by synicole          #+#    #+#             */
/*   Updated: 2023/05/23 11:20:13 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_last_exit_code;

/**
 * Use argv[2] as input for checker
 * @param argv
 * @param env
 */
static void	ft_for_checker(char **argv, t_env env)
{
	char	**arg_input;
	int		i;

	arg_input = ft_split(argv[2], ';');
	if (!arg_input)
		ft_exit(EXIT_FAILURE, "invalid input\n");
	i = 0;
	while (arg_input[i])
	{
		ft_init_signals();
		if (arg_input[i] && !ft_contains_only_space(arg_input[i]))
		{
			ft_parsing(&env, arg_input[i]);
			ft_execute(&env);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt_output;
	t_env	env;

	ft_init_env(&env, envp);
	prompt_output = "";
	if (argc == 3 && ft_strncmp(argv[1], "-c", 3) == 0 && argv[2])
		ft_for_checker(argv, env);
	else
	{
		while (prompt_output != NULL)
		{
			ft_init_signals();
			prompt_output = readline("minishell-1.0$ ");
			if (prompt_output && !ft_contains_only_space(prompt_output))
			{
				add_history(prompt_output);
				ft_parsing(&env, prompt_output);
				ft_execute(&env);
				ft_free_token(&env);
				ft_free_cmd(&env);
			}
		}
	}
	return (g_last_exit_code);
}
