/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:19:35 by synicole          #+#    #+#             */
/*   Updated: 2023/04/28 12:19:37 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**token_to_char(t_token *env)
{
	char	**envp;
	t_token	*tmp;
	int		i;

	envp = malloc(sizeof(char) * (size_list(env) + 1));
	if (!envp)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		envp[i] = tmp->str;
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
