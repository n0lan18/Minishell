/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:31:22 by synicole          #+#    #+#             */
/*   Updated: 2023/05/07 17:31:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Initializes the environment variables.
 *
 * @param env pointer to the t_env structure to be initialized
 * @param envp array of strings containing the environment variables
 *
 * @return void
 */
void	ft_init_envp(t_env *env, char **envpchar)
{
	t_envp	*envp;
	int		i;

	env->envp = ft_new_envp(envpchar[0]);
	i = 1;
	while (envpchar[i])
	{
		envp = ft_new_envp(envpchar[i]);
		ft_add_envp_end(&env->envp, envp);
		i++;
	}
}

/**
 * Gets the name of an environment variable.
 * @param str
 *
 * @return char*
 */
char	*ft_get_envp_name(const char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	name = malloc(sizeof(char) * (i + 1));
	if (!name)
		ft_exit(EXIT_FAILURE, "malloc error");
	i = 0;
	while (str[i] && str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 0;
	return (name);
}

/**
 * Gets the value of an environment variable.
 * @param str
 *
 * @return char*
 */
char	*ft_get_envp_value(const char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	if (!str[i])
		return (NULL);
	j = i;
	while (str[j])
		j++;
	value = malloc(sizeof(char) * (j - i + 1));
	if (!value)
		ft_exit(EXIT_FAILURE, "malloc error");
	j = 0;
	while (str[i])
	{
		value[j] = str[i];
		j++;
		i++;
	}
	value[j] = 0;
	return (value);
}
