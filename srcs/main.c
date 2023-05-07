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

//int	main(int argc, char **argv, char **envp)
//{
//	char	*prompt_output;
//	char	**arg_input;
//	t_token	*tokens;
//	t_token	*env;
//	int		i;
//
//	env = NULL;
//	env = env_in_list(envp, env);
//	prompt_output = "";
//	if (argc == 3 && ft_strncmp(argv[1], "-c", 3) == 0 && argv[2])
//	{
//		arg_input = ft_split(argv[2], ';');
//		if (!arg_input)
//			ft_close();
//		i = 0;
//		while (arg_input[i])
//		{
//			if (!arg_input[i])
//				ft_close();
//			tokens = ft_readline_to_tokens(arg_input[i]);
//			tokens = good_parse(tokens, env);
//			if (tokens)
//			{
//				ft_assign_type_for_each_token(tokens);
//				if (!check_if_built(tokens, env))
//					check_if_command(tokens, env);
//				while (tokens)
//					tokens = tokens->next;
//			}
//			i++;
//		}
//	}
//	else
//	{
//		while (prompt_output != NULL)
//		{
//			ft_init_signals();
//			prompt_output = readline("minishell-1.0$ ");
//			if (!prompt_output)
//				ft_close();
//			tokens = ft_readline_to_tokens(prompt_output);
////			tokens = good_parse(tokens, env);
////			if (!tokens)
////				continue ;
////			ft_assign_type_for_each_token(tokens);
////			if (!check_if_built(tokens, env))
////				check_if_command(tokens, env);
//			while (tokens)
//			{
//				db_print_token(tokens);
//				tokens = tokens->next;
//			}
//			add_history(prompt_output);
//		}
//	}
//	return (0);
//}

int	g_last_exit_code;

int	main(int argc, char **argv, char **envp)
{
	char	*prompt_output;
	t_env	env;

	(void)argc;
	(void)argv;
	ft_init_env(&env, envp);
	prompt_output = "";
	db_print_tab(ft_envp_to_char(env.envp));
	while (prompt_output != NULL)
	{
		ft_init_signals();
		prompt_output = readline("minishell-1.0$ ");
		if (prompt_output && !ft_contains_only_space(prompt_output))
		{
			ft_parsing(&env, prompt_output);
			add_history(prompt_output);
		}
	}
	return (g_last_exit_code);
}
