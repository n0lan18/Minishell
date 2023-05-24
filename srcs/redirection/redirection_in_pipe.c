/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_in_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:00:02 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/24 14:17:06 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_if_redirection(t_cmd *cmd)
{
	int	fd;

	fd = 0;
	if (!ft_strncmp(cmd->name, '>', ft_strlen(cmd->name)))
		fd = open(cmd->option[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (!ft_strncmp(cmd->name, '<', ft_strlen(cmd->name)))
		fd = open(cmd->option[1], O_RDONLY)
}