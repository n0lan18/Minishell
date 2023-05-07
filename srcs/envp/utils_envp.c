/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:32:21 by synicole          #+#    #+#             */
/*   Updated: 2023/05/07 17:32:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Converts a linked list of environment variables to an array of strings.
 * @param envp
 *
 * @return t_envp*
 */
char	**ft_envp_to_char(t_envp *envp)
{
	char	**envpchar;
	t_envp	*tmp;
	int		i;

	envpchar = malloc(sizeof(char) * (ft_size_list_envp(envp) + 1));
	if (!envpchar)
		ft_exit(EXIT_FAILURE, "malloc error");
	tmp = envp;
	i = 0;
	while (tmp)
	{
		envpchar[i] = tmp->line;
		tmp = tmp->next;
		i++;
	}
	envpchar[i] = 0;
	return (envpchar);
}
