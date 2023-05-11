/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:27:14 by synicole          #+#    #+#             */
/*   Updated: 2023/05/10 19:15:31 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Parses the readline and creates a linked list of tokens.
 * @param env
 * @param readline
 */
void	ft_parsing(t_env *env, char *readline)
{
	ft_readline_to_token(env, readline);
	ft_dollar(env);
	ft_trim_quote(env);
	ft_join_token_not_separate_by_space(env);
	init_type_in_list(env);
}
