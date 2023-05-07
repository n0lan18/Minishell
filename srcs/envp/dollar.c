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

void	ft_replace_envvar(t_env *env, t_token *current)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_substr(current->str, 0, ft_strchr(current->str, '$') - current->str);
	tmp2 = ft_getenv(env->envp, ft_substr(current->str, ft_strchr(current->str, '$') - current->str + 1, ft_strlen(current->str)));
	tmp3 = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	free(current->str);
	current->str = tmp3;
}

void	ft_dollar(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->type == E_STRING && current->quote != E_SINGLE_QUOTE)
			if (ft_contains_dollar(current->str))
				ft_replace_envvar(env, current);
		current = current->next;
	}
}
