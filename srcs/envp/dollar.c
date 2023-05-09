/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:15:22 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 22:15:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_getenv(t_envp *envp, char *name)
{
	t_envp	*current;

	current = envp;
	while (current)
	{
		if (ft_strncmp(current->name, name, ft_strlen(name)) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	ft_create_list_dollars(t_dollar **list_dollars, char **tab_dollars)
{
	int			i;
	t_dollar	*new;

	i = 0;
	while (tab_dollars[i])
	{
		new = malloc(sizeof(t_dollar));
		new->str = tab_dollars[i];
		new->next = NULL;
		ft_add_dollar_end(list_dollars, new);
		i++;
	}
}

void	ft_replace_dollar(t_env *env, t_token *current)
{
	char		**tab_dollars;
	t_dollar	*list_dollars;

	(void)env;
	list_dollars = NULL;
	tab_dollars = ft_split_dollar(ft_strtrim(current->str, "\""));
	ft_create_list_dollars(&list_dollars, tab_dollars);
	db_print_dollar(list_dollars);
}

void	ft_dollar(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->type == E_STRING && current->quote != E_SINGLE_QUOTE)
			if (ft_contains_dollar(current->str))
				ft_replace_dollar(env, current);
		current = current->next;
	}
}
