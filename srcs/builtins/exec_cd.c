/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:14:25 by synicole          #+#    #+#             */
/*   Updated: 2023/04/25 23:14:28 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Executes the cd command.
 * @param t_token *list
 *
 * @return void
 */
void	ft_exec_cd(t_token *list)
{
	char	*path;

	if (!list->next)
	{
		if (chdir(getenv("HOME")))
			perror(ft_strjoin("minishell: cd: ", path));
	}
	else
	{
		path = list->next->next->str;
		if (chdir(path))
			perror(ft_strjoin("minishell: cd: ", path));
	}
}
