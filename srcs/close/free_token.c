/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:01:41 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 13:47:54 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Frees the token list from the given environment.
 * @param t_token *token the token list to free
 *
 * @return void
*/
void	ft_free_token(t_env *env)
{
	t_token	*tmp;

	while (env->token)
	{
		tmp = env->token;
		env->token = env->token->next;
		if (env->token)
			free(tmp->str);
		free(tmp);
	}
}

void	ft_free_liste_token(t_env *env)
{
	t_token	*tmp;
	t_token	*tmp_next;

	tmp = env->token;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
}
