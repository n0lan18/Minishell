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

int	main(void)
{
	char	*prompt_output;
	t_token	*tokens;

	prompt_output = "";
	while (prompt_output != NULL)
	{
		ft_init_signals();
		prompt_output = readline("minishell-1.0$ ");
		if (!prompt_output)
			ft_close();
		tokens = ft_readline_to_tokens(prompt_output);
		ft_assign_type_for_each_token(tokens);
		while (tokens)
		{
			db_print_token(tokens);
			tokens = tokens->next;
		}
		add_history(prompt_output);
	}
	return (0);
}

//int	main(void)
//{
//	printf("%d\n", ft_count_words("helloworld"));
//}
