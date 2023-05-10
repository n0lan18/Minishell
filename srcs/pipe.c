/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:22:57 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/10 11:38:58 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	if_pipe_in_list(t_token *list)
{
	t_token	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		if (tmp->type == 3)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_token	*list_without_space_for_pipe(t_token *list)
{
	t_token	*tmp;
	t_token	*new;

	tmp = list;
	while (tmp)
	{
		if (tmp->type != 0)
			new = add_new_element(new, tmp->str);
		tmp = tmp->next;
	}
	return (new);
}

void	run_pipeline(t_token *list)
{
	t_token	*tmp;
	t_token	*new;

	tmp = list;
	new = list_without_space_for_pipe(tmp);
	while (new)
	{
		printf("%s\n", new->str);
		new = new->next;
	}
}