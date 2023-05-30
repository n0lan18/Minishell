/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_in_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:00:02 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/25 16:44:23 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_check_if_redirection(t_cmd *cmd, int *redirection)
{
	if (!ft_strncmp(cmd->name, ">", ft_strlen(cmd->name)))
		*redirection = open(cmd->option[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (!ft_strncmp(cmd->name, "<", ft_strlen(cmd->name)))
		*redirection = open(cmd->option[1], O_RDONLY);
	if (*redirection == -1)
	{
		perror("kkk");
		exit(EXIT_FAILURE);
	}
	cmd = cmd->next;
}
