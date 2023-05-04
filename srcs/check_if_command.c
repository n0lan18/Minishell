/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:51:27 by synicole          #+#    #+#             */
/*   Updated: 2023/05/03 19:35:22 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*Fonction qui execute la commande avec son fichier*/
void	fork_in_child_proc(char *str, char **envp, char **args, char *cmd_path)
{
	int	fd_open;

	fd_open = open(str, O_RDONLY);
	if (fd_open == -1)
	{
		perror(str);
		exit(1);
	}
	if (dup2(fd_open, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		perror("execve");
		exit(1);
	}
}

/*La fonction executue la suite de la fonction child_process. Elle fork a chaque
fois qu'elle rencontre un fichier et léxecute avec la commande qu'elle genere*/
void	child_process_bis(char **args, char *path, t_token *env, t_token *tmp)
{
	pid_t	pid;
	char	**envp;

	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type != 0)
		{
			envp = token_to_char(env);
			pid = fork();
			if (pid < 0)
			{
				perror("fork");
				exit(1);
			}
			else if (pid == 0)
				fork_in_child_proc(tmp->str, envp, args, path);
			else
				parent_process(pid);
		}
		tmp = tmp->next;
	}
}

/*Execute la commande avec son ou ses fichier avec un fork*/
void	child_process(char *cmd, char *cmd_path, t_token *env, t_token *list)
{
	t_token	*tmp;
	char	*args[2];

	args[0] = cmd;
	args[1] = NULL;
	if (cmd_path == NULL)
	{
		printf("minishell: %s: command not found\n", cmd);
		exit(1);
	}
	tmp = list;
	child_process_bis(args, cmd_path, env, tmp);
	exit(EXIT_SUCCESS);
}

void	parent_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			printf("Failed command with code %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
		printf("Failed command by signal %d\n", WTERMSIG(status));
}

/*Commande d'entree, elle fork pour executer la commande trouvée*/
void	check_if_command(t_token *list, t_token *env)
{
	char	*cmd;
	char	*cmd_path;
	pid_t	pid;

	cmd = list->str;
	cmd_path = NULL;
	find_cmd_path(cmd, &cmd_path, env);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
		child_process(cmd, cmd_path, env, list);
	else
		parent_process(pid);
}
