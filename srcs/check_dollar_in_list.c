/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollar_in_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:29 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/03 12:58:43 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*replace_dollar_if_first(t_list *list, char **env)
{
	t_list	*tmp;
	t_list	*new_element;
	char	*str;

	if (size_list(list) <= 1)
		return (list);
	tmp = list;
	if (tmp->str[0] == '$' && tmp->next->str[0] != ' ')
	{
		if (tmp->str[0] == '$' && tmp->next->str[0] != '$')
		{
			str = search_var_in_env(tmp->next->str, env);
			tmp->next->str = add_var_and_word(tmp->next->str, str, tmp->str);
			new_element = tmp->next;
			free(tmp);
			return (new_element);
		}
	}
	return (list);
}

t_list	*replace_dollar_if_after(t_list *list, t_list *tmp, char **env)
{
	t_list	*temp;
	int		i;

	i = 0;
	list = tmp;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (list);
		if (tmp->str[0] == 39)
		{
			while (i < search_case_in_list(tmp, "'"))
			{
				tmp = tmp->next;
				i++;
			}
		}
		else if (tmp->next->str[0] == '$')
			tmp = replace_dollar_if_after_bis(temp, tmp, env);
		if (tmp->next == NULL || tmp == NULL)
			return (list);
		temp = tmp;
		tmp = tmp->next;
	}
	return (list);
}

t_list	*replace_dollar_if_after_bis(t_list *temp, t_list *tmp, char **env)
{
	char	*str;

	str = NULL;
	while (tmp)
	{
		temp = tmp;
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
		if (tmp->next->str[0] != '$')
			break ;
	}
	if (tmp->next->str[0] != ' ')
	{
		str = search_var_in_env(tmp->next->str, env);
		tmp->next->str = add_var_and_word(tmp->next->str, str, tmp->str);
		temp->next = tmp->next;
		free(tmp);
		tmp = temp;
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	*replace_if_dollar(t_list *list, char **env)
{
	t_list	*tmp;

	tmp = list;
	tmp = replace_dollar_if_first(tmp, env);
	if (size_list(tmp) <= 1)
		return (tmp);
	list = replace_dollar_if_after(list, tmp, env);
	return (list);
}
