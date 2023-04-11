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

t_list	*add_new_element(t_list *list, char *tab)
{
	t_list	*new_element;
	t_list	*tmp;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	tmp = list;
	new_element->str = ft_strcpy_new
			(new_element->str, tab, 0, ft_strlen(tab) - 1);
	new_element->next = NULL;
	if (tmp == NULL)
		return (new_element);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_element;
	}
	return (list);
}

void	free_list(t_list *a)
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

t_list	*remove_first_elem_list(t_list *list)
{
	t_list	*tmp;
	t_list	*first_elem;
	int i;

	tmp = list;
	i = 0;
	if (list == NULL)
		return (NULL);
	if ((tmp->str[0] == '$' && tmp->next->str[0] == '$') || \
	(tmp->str[0] == '$' && tmp->next->str[0] == ' '))
	{
		while (tmp->next->str[0] == '$' && tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
	}
	if (tmp->str[0] == '$' && tmp->next->str[0] != ' ' && (i % 2) == 0)
	{
		first_elem = tmp->next;
		free(tmp);
		return (first_elem);
	}
	else
		return (list);
}

t_list	*remove_after_first_elem_list(t_list *list)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = list;
	if (size_list(list) < 2)
		return (list);
	while (tmp->next)
	{
		if (tmp->str[0] == 39)
			while (tmp->next && tmp->next->str[0] != 39)
				tmp = tmp->next;
		temp = tmp;
		if (tmp->next == NULL)
			return (list);
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (list);
		printf("tmp %c\n", tmp->str[0]);
		printf("tmp next %c\n", tmp->next->str[0]);
		if ((tmp->str[0] == '$' && tmp->next->str[0] == ' ') || (temp->str[0] == ' ' && tmp->str[0] == '$' && tmp->next->str[0] == ' ') || (temp->str[0] == '$' && tmp->str[0] == '$' && tmp->next->str[0] == ' '))
		{
			printf("KKKK\n");
			temp->next = tmp->next;
			free(tmp);
			tmp = temp;
		}
	}
	return (list);
}

int	size_list(t_list *list)
{
	t_list	*tmp;
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
