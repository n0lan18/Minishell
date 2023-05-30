/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:38:23 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 11:25:42 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Merges current token with the next one.
 * @param current
 *
 * @return void
 */
static void	ft_merge_token(t_token *current)
{
	char	*tmp;

	tmp = ft_strjoin(current->str, current->next->str);
	free(current->str);
	current->str = tmp;
	current->next = current->next->next;
}

static void	ft_remove_if_space_before_and_after(t_token *tmp)
{
	while (tmp)
	{
		if (tmp != NULL && tmp->next != NULL && tmp->next->next != NULL)
		{
			if ((tmp->next->type == E_SPACE && \
					tmp->next->next->type == E_PIPE) || \
				(tmp->next->type == E_SPACE && \
					tmp->next->next->type == E_REDIRECTION))
			{
				tmp->next = tmp->next->next;
				tmp = tmp->next;
			}
			else if ((tmp->type == E_PIPE && tmp->next->type == E_SPACE) || \
			(tmp->type == E_REDIRECTION && tmp->next->type == E_SPACE))
			{
				tmp->next = tmp->next->next;
				tmp = tmp->next;
			}
			else
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
}

/**
 * Joins tokens that are not separated by a space if this is not
 * a pipe or < >.
 * @param env
 *
 * @return void
 */
void	ft_join_token_not_separate_by_space(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current->next)
	{
		if (current->str[0] == '|' || current->str[0] == '>' || \
		current->str[0] == '<')
			current = current->next;
		else if (current->str[0] != ' ' && current->next->str[0] != ' ' && \
				current->next->str[0] != '|' && current->next->str[0] != '>' && \
				current->next->str[0] != '<')
			ft_merge_token(current);
		else
			current = current->next;
	}
	current = env->token;
	ft_remove_if_space_before_and_after(current);
}
