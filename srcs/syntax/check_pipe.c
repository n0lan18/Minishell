/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:30:29 by synicole          #+#    #+#             */
/*   Updated: 2023/05/28 16:30:30 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_pipe_error(t_token *token)
{
	t_token	*cpy;

	cpy = token;
	while (cpy->previous != NULL && cpy->previous->type == E_SPACE)
		cpy = cpy->previous;
	if (cpy->previous != NULL)
	{
		if (cpy->previous->type != E_STRING)
			return (1);
	}
	if (cpy->previous == NULL)
		return (1);
	cpy = token;
	while (cpy->next != NULL && cpy->next->type == E_SPACE)
		cpy = cpy->next;
	if (cpy->next != NULL)
	{
		if (cpy->next->type != E_STRING && cpy->next->type != E_REDIRECTION)
			return (1);
	}
	if (cpy->next == NULL)
		return (1);
	return (0);
}

int	ft_pipe_is_valid(t_token *token)
{
	if (token->type == E_PIPE)
	{
		if (ft_pipe_error(token))
			return (0);
		else
			return (1);
	}
	return (1);
}
