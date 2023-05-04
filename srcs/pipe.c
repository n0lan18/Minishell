/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:42:48 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/03 19:29:17 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_if_pipe_in_list(t_token *list)
{
	t_token	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->type == 8 && tmp->next != NULL)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
void	pipe_cmd(t_token *list, t_token *env)
{
	int		pipefd[2];
	int		pipefd2[2];
	pid_t	pid1;
	pid_t	pid2;

	while (i < check_many_cmd(list))
	{
		pipe(pipefd);
		pipe(pipefd2);
		if (pipe(pipefd) == -1 || pipe(pipefd2) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		pid1 = fork();
		if (pid1 == 0)
		{
			if (i + 1 != check_many_cmd(list))
				dup2(STDOUT_FILENO, pipefd[1]);
			close(pipefd[0]);
			close(pipefd2[1]);
			kk = ft_split(tab[j], ' ');
			pathname = exist_of_cmd(envp, kk[0]);
			execve(pathname, kk, envp);
			free_double_tab(kk);
		}
		i++;
		if (i == check_many_cmd(list))
			break ;
		while (pathname == NULL && tab[j])
			pathname = exist_of_cmd(envp, tab[j++]);
		printf("TAB2 %s\n", tab[j]);
		pid2 = fork();
		if (pid2 == 0)
		{
			if (i + 1 == check_many_cmd(list))
				dup2(pipefd[1], STDOUT_FILENO);
			else
			{
				dup2(STDIN_FILENO, pipefd[0]);
				dup2(STDOUT_FILENO, pipefd2[1]);
				close(pipefd[1]);
				close(pipefd2[0]);
			}
			kk = ft_split(tab[j], ' ');
			pathname = exist_of_cmd(envp, kk[0]);
			execve(pathname, kk, envp);
			free_double_tab(kk);
		}
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		i++;
	}
	close(pipefd[1]);
	close(pipefd[0]);
	close(pipefd2[1]);
	close(pipefd2[0]);
}
*/