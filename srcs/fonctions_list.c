/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:18:27 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/26 16:36:25 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_element(t_token *list, char *tab)
{
	t_token	*new_element;
	t_token	*tmp;

	tmp = list;
	new_element = malloc(sizeof(t_token));
	if (!new_element)
		return ;
	new_element->str = ft_strcpy_new(new_element->str, tab, \
	0, ft_strlen(tab) - 1);
	new_element->next = NULL;
	free(tab);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_element;
}

void	free_list(t_token *a)
{
	t_token	*temp;
	t_token	*temp_next;

	temp = a;
	while (temp)
	{
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
}

int	search_case_in_list(t_token *list, char *str)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp && tmp->str != str)
	{
		i++;
		tmp = tmp->next;
	}
	i++;
	return (i);
}

int	size_list(t_token *list)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
