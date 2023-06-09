/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:58:21 by synicole          #+#    #+#             */
/*   Updated: 2023/05/28 15:58:25 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Check if the syntax is valid.
 *
 * @param env
 *
 * @return void
 */
static void	ft_check_syntax(t_env *env)
{
	while (env->token)
	{
		if (!ft_quote_is_valid(env->token->str))
		{
			env->syntax_error_type = E_SYNTAX_QUOTE_CLOSE;
			return ;
		}
		else if (!ft_redirection_is_valid(env->token))
		{
			env->syntax_error_type = E_SYNTAX_REDIRECTION;
			return ;
		}
		else if (!ft_pipe_is_valid(env->token))
		{
			env->syntax_error_type = E_SYNTAX_PIPE;
			return ;
		}
		env->token = env->token->next;
	}
	env->syntax_error_type = 0;
}

/**
 * Display the syntax error.
 *
 * @param syntax_error_type
 *
 * @return void
 */
static void	ft_display_error_syntax(int syntax_error_type)
{
	if (syntax_error_type == E_SYNTAX_QUOTE_CLOSE)
		ft_putstr_fd("minishell: syntax error quote is not closed\n", 2);
	else if (syntax_error_type == E_SYNTAX_REDIRECTION)
		ft_putstr_fd(
			"minishell: syntax error near unexpected token `<' or `>'\n", 2);
	else if (syntax_error_type == E_SYNTAX_PIPE)
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	g_last_exit_code = 258;
}

/**
 * Check if there is a syntax error in the command line.
 *
 * @param env
 *
 * @return 1 if there is a syntax error, 0 otherwise.
 */
int	ft_has_syntax_error(t_env *env)
{
	t_token	*start;

	start = env->token;
	ft_check_syntax(env);
	if (env->syntax_error_type)
	{
		env->token = start;
		ft_display_error_syntax(env->syntax_error_type);
		return (1);
	}
	env->token = start;
	return (0);
}
