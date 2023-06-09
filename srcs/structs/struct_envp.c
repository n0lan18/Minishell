/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:02:47 by synicole          #+#    #+#             */
/*   Updated: 2023/05/07 18:02:48 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Replaces the value of an envp.
 * @param current
 * @param new
 *
 * @return void
 */
static void	ft_replace_envp(t_envp *current, t_envp *new)
{
	current->value = ft_strdup(new->value);
	current->line = ft_strdup(new->line);
}

/**
 * Creates a new envp.
 * @param str
 *
 * @return t_envp *new
 */
t_envp	*ft_new_envp(char *str)
{
	t_envp	*new;

	new = malloc(sizeof(t_envp));
	if (!new)
		return (NULL);
	new->line = ft_strdup(str);
	new->name = ft_get_envp_name(str);
	new->value = ft_get_envp_value(str);
	new->next = NULL;
	return (new);
}

/**
 * Adds a new envp at the end of the given list.
 * @param t_envp **list the current list of envp to add to
 * @param t_envp *new the new envp to add
 *
 * @return void
*/
void	ft_add_envp_end(t_envp **lst, t_envp *new)
{
	t_envp	*current;

	current = *lst;
	if (!current)
		return ;
	else
	{
		while (current->next)
		{
			if (ft_strncmp(current->name, new->name, ft_strlen(new->name) + 1)
				== 0)
			{
				ft_replace_envp(current, new);
				return ;
			}
			current = current->next;
		}
		if (ft_strncmp(current->name, new->name, ft_strlen(new->name) + 1)
			== 0)
			ft_replace_envp(current, new);
		else
			current->next = new;
	}
}

/**
 * Removes the envp with the given name from the given list.
 * @param t_envp *list the current list of envp to remove from
 * @param char *str the name of the envp to remove
 *
 * @return void
*/
void	ft_remove_envp(t_envp **lst, char *str)
{
	t_envp	*current;
	t_envp	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (ft_strncmp(current->name, str, ft_strlen(str) + 1) == 0)
		{
			if (!prev)
				*lst = current->next;
			else
				prev->next = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

/**
 * Returns the size of the given envp list.
 * @param t_envp *list the list of envp to count
 *
 * @return int the size of the list
*/
int	ft_size_list_envp(t_envp *list)
{
	int		i;
	t_envp	*current;

	i = 0;
	current = list;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
