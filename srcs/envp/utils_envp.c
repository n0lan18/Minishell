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
	int		i;

	envpchar = malloc(sizeof(char *) * (ft_size_list_envp(envp) + 1));
	if (!envpchar)
		ft_exit(EXIT_FAILURE, "malloc error");
	i = 0;
	while (envp)
	{
		envpchar[i] = envp->line;
		envp = envp->next;
		i++;
	}
	envpchar[i] = NULL;
	return (envpchar);
}

/**
 * Checks if the character is allowed in an environment variable name.
 * @param c
 *
 * @return int
 */
int	ft_valid_identifier(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
		return (1);
	return (0);
}

/**
 * Gets the size of the linked list of environment variables.
 * @param envp
 * @param name
 *
 * @return char*
 */
char	*ft_get_envp_value_by_name(t_envp *envp, char *name)
{
	t_envp	*current;

	current = envp;
	while (current)
	{
		if (ft_strncmp(current->name, name, ft_strlen(name) + 1) == 0)
			return (ft_strdup(current->value));
		current = current->next;
	}
	return (ft_strdup(""));
}

/**
 * Gets the PATH environment variable and splits it into an array of strings.
 * @param envp
 *
 * @return char**
 */
char	**ft_get_splited_path(t_envp *envp)
{
	char	*unsplited_path;
	char	**splited_path;

	unsplited_path = ft_get_envp_value_by_name(envp, "PATH");
	if (unsplited_path[0] == '\0')
	{
		free(unsplited_path);
		return (NULL);
	}
	splited_path = ft_split(unsplited_path + 5, ':');
	return (splited_path);
}
