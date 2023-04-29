/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_list_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:27:36 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/29 01:57:18 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*free_if_space_at_last(t_token *list)
{
	t_token	*tmp;
	t_token	*prev;

	tmp = list;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (just_space(tmp->str) == 0)
	{
		prev->next = NULL;
		free(tmp);
	}
	return (list);
}

int	just_space(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

t_token	*together_if_not_space_bis(t_token *tmp, char *str, t_token *new)
{
	while (tmp)
	{
		str = tmp->str;
		tmp = tmp->next;
		if (tmp == NULL)
		{
			if (str)
				new = add_new_element(new, str);
			free(str);
			break ;
		}
		if (just_space(str) == 1 && just_space(tmp->str) == 1)
		{
			while (tmp && just_space(tmp->str) != 0)
			{
				str = ft_strjoin(str, tmp->str);
				tmp = tmp->next;
			}
			new = add_new_element(new, str);
		}
		else if (just_space(tmp->str) == 0)
			new = together_if_not_space_bis_bis(tmp->str, str, new);
		free(str);
	}
	return (new);
}

t_token	*together_if_not_space_bis_bis(char *tmp, char *str, t_token *new)
{
	new = add_new_element(new, str);
	new = add_new_element(new, tmp);
	return (new);
}

t_token	*together_if_not_space(t_token *list)
{
	t_token	*tmp;
	t_token	*new;
	char	*str;

	str = NULL;
	new = NULL;
	tmp = list;
	if (!list)
		return (NULL);
	if (tmp->next == NULL)
		return (tmp);
	tmp = free_if_space_at_last(tmp);
	new = together_if_not_space_bis(tmp, str, new);
	return (new);
}
