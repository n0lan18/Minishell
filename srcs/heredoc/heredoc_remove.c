/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:38:05 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 17:38:06 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_del_file(char *str)
{
	char	**option;
	pid_t	pid_fork;

	option = ft_calloc(sizeof(char *), 3);
	if (!option)
		exit(printf("Error Malloc\n") + 247);
	option[0] = ft_strdup("/bin/rm");
	if (!option[0])
		exit(printf("Error Malloc\n") + 247);
	option[1] = ft_strdup(str);
	if (!option[1])
		exit(printf("Error Malloc\n") + 247);
	if (access(str, F_OK) == 0)
	{
		pid_fork = fork();
		if (pid_fork == 0)
			execve(option[0], option, NULL);
	}
	free(option[1]);
	free(option[0]);
	free(option);
}

void	ft_heredoc_remove(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (ft_strncmp(current->str, ".heredoc", ft_strlen(".heredoc")) == 0)
			ft_del_file(current->str);
		current = current->next;
	}
}
