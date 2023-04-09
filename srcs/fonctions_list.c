/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:18:27 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/06 09:18:32 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*add_new_element(t_list *liste, char *tab)
{
	t_list	*new_element;
	t_list	*tmp;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	tmp = liste;
	new_element->str = ft_strcpy_new(new_element->str, tab, 0, ft_strlen(tab) - 1);
	new_element->next = NULL;
	if (tmp == NULL)
		return (new_element);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_element;
	}
	return (liste);
}

t_list	*char_to_tab(char *tab, t_list *liste)
{
	t_list	*tmp;

	tmp = liste;
	tmp = add_new_element(tmp, tab);
	return (tmp);
}

void	free_liste(t_list *a)
{
	t_list	*temp;
	t_list	*temp_next;

	temp = a;
	while (temp)
	{
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
}

void	free_element(t_list *a)
{
	t_list *tmp;
	t_list *tmp_next;

	tmp = a;
	tmp_next = tmp->next;
	free(tmp);
	tmp = tmp_next;
}