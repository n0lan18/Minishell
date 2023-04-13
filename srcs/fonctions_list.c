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

	tmp = list;
	first_elem = tmp;
	if (list == NULL)
		return (NULL);
	if (tmp->str[0] == '$')
	{
		if (tmp->next->str[0] != '$')
		{
			first_elem = tmp->next;
			free(tmp);
			return (first_elem);
		}
	}
	return (list);
}

t_list	*remove_after_first_elem_list(t_list *list)
{
	t_list	*tmp;
	t_list	*temp;
	int i;

	tmp = list;
	if (size_list(list) < 2)
		return (list);
	while (tmp)
	{
		temp = tmp;

		if (tmp == NULL)
			return (list);
		if (tmp->str[0] == '$')
		{
			if((i % 2) == 0)
			{
				printf("oooooooo\n");
				if (tmp->next->str[0] != '$' || tmp->next->str[0] != ' ')
				{
					printf("lllllll\n");
					printf("temp %s\n", temp->str);
					printf("tmp next %s\n", tmp->next->str);
					temp->next = tmp->next;
					free(tmp);
					tmp = temp;
				}
				i = 0;
			}
		}
		tmp = tmp->next;
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

int number_of_dollar(t_list *list)
{
	int i;
	t_list	*tmp;

	i = 1;
	tmp = list;
	while (tmp)
	{
		if (tmp->str[0] != '$')
			break;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_list	*maj_list(t_list *list, int num)
{
	t_list	*tmp;
	int i;

	tmp = list;
	i = 0;
	while (i <= num)
	{
		i++;
		tmp = tmp->next;
	}
	return (tmp);
}
