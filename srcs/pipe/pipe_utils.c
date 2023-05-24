/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:25:00 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/24 10:39:28 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_if_there_is_pipe(t_env *env)
{
	t_token	*tmp;

	tmp = env->token;
	while (tmp)
	{
		if (tmp->type == E_PIPE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	**init_fd_for_pipe(int **fd, int num_cmd)
{
	int	i;

	i = 0;
	fd = malloc(sizeof(*fd) * num_cmd);
	if (!fd)
		return (NULL);
	while (i < num_cmd)
	{
		fd[i] = malloc(sizeof(**fd) * 2);
		if (!fd[i])
			return (NULL);
		i++;
	}
	return (fd);
}
