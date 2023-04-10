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

t_list	*remove_first_elem_liste(t_list *liste)
{
	t_list	*tmp;
	t_list	*first_elem;

	tmp = liste;
	if (liste == NULL)
		return (NULL);
	else
	{
		if (tmp->str[0] == '$' && tmp->next->str[0] != ' ')
		{
			first_elem = tmp->next;
			free(tmp);
			return (first_elem);
		}
		else
			return (liste);
	}
}

t_list	*remove_after_first_elem_liste(t_list *liste)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = liste;
	if (size_liste(liste) < 2)
		return (liste);
	while (tmp->next)
	{
		temp = tmp;
		if (tmp->str[0] == 39)
		{
			while (tmp && tmp->next->str[0] != 39)
				tmp = tmp->next;
			if (tmp->next == NULL)
				return (liste);
		}
		if (tmp->next->str[0] == '$')
		{
			tmp = tmp->next;
			temp->next = tmp->next;
			free(tmp);
			tmp = temp;
		}
		if (tmp->next == NULL)
			return (liste);
		tmp = tmp->next;
	}
	return (liste);
}

int size_liste(t_list *liste)
{
	t_list	*tmp;
	int i;

	i = 0;
	tmp = liste;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}