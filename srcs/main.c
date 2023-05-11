/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:23:50 by synicole          #+#    #+#             */
/*   Updated: 2023/05/11 19:07:23 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_last_exit_code;

void	ft_for_checker(char **argv, t_env env)
{
	char	**arg_input;
	int		i;

	arg_input = ft_split(argv[2], ';');
	if (!arg_input)
		ft_close();
	i = 0;
	while (arg_input[i])
	{
		ft_init_signals();
		if (arg_input[i] && !ft_contains_only_space(arg_input[i]))
		{
			ft_parsing(&env, arg_input[i]);
			if (ft_strncmp(env.token->str, "echo", 5) == 0)
				ft_run_echo(env.token);
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
				ft_parsing(&env, prompt_output);
				if (check_if_cmd_first(env) == 1)
					launch_cmd(env);
				else if (ft_strncmp(env.token->str, "echo", 5) == 0)
					ft_run_echo(env.token);
			//	db_print_token(env.token);
				add_history(prompt_output);
			}
		}
	}
	return (g_last_exit_code);
}
