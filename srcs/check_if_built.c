/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_built.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:48:35 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/24 23:48:41 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_if_built(t_token *list, t_token *env)
{
	if (ft_strncmp(list->str, "echo", ft_strlen(list->str)) == 0)
		launch_echo(list);
	else if (ft_strncmp(list->str, "env", ft_strlen(list->str)) == 0)
		launch_env(env);
	else if (ft_strncmp(list->str, "export", ft_strlen(list->str)) == 0)
		launch_export(env, list);
	else if (ft_strncmp(list->str, "unset", ft_strlen(list->str)) == 0)
		launch_unset(env, list);
	else if (ft_strncmp(list->str, "exit", ft_strlen(list->str)) == 0)
		exit(EXIT_SUCCESS);
}
