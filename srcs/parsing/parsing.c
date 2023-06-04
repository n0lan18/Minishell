/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:27:14 by synicole          #+#    #+#             */
/*   Updated: 2023/05/17 00:37:53 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Parses the readline and creates a linked list of tokens and commands.
 *
 * @param env
 * @param readline
 *
 * @return void
 */
void	ft_parsing(t_env *env, char *readline)
{
	ft_readline_to_token(env, readline);
	if (!ft_has_syntax_error(env))
	{
		ft_heredoc(env);
		if (!env->syntax_error_type)
		{
//			ft_dollar(env);
			ft_trim_quote(env);
			ft_join_token_not_separate_by_space(env);
			ft_command(env);
		}
	}
	if (DEBUG_TOKEN)
		db_print_token(env->token);
	if (DEBUG_CMD)
		db_print_cmd(env->cmd);
}
