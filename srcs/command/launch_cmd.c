/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:24:44 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/12 11:33:28 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

///**
// * This fonction launch the cmd if there is a file in the list. The i variable
// * is a counter for the execve fonction and not created here for the norm.
// * @param tmp
// * @param path
// * @param cmd
// * @param i
// *
// * @return void
// */
//void	launch_cmd_if_file_in_list(t_token *tmp, char **path, char **cmd, int i)
//{
//	int		status;
//	pid_t	pid;
//
//	while (tmp)
//	{
//		i = -1;
//		if (tmp->type == E_FILE)
//		{
//			pid = fork();
//			if (pid < 0)
//			{
//				perror("fork");
//				exit(EXIT_FAILURE);
//			}
//			if (pid == 0)
//			{
//				dup2(open(tmp->str, O_RDONLY), STDIN_FILENO);
//				while (path[++i])
//					execve(path[i], cmd, NULL);
//			}
//			else
//				waitpid(pid, &status, 0);
//		}
//		tmp = tmp->next;
//	}
//}
//
///**
// * This fonction launch the cmd if there is no file in the list. The i variable
// * is a counter for the execve fonction and not created here for the norm.
// * @param path
// * @param options
// * @param i
// *
// * @return void
// */
//void	launch_cmd_without_file(char **path, char **options, int i)
//{
//	pid_t	pid;
//	int		status;
//
//	printf("launch cmd without file\n");
//	i = -1;
//	pid = fork();
//	if (pid < 0)
//	{
//		perror("fork");
//		exit(EXIT_FAILURE);
//	}
//	if (pid == 0)
//		while (path[++i])
//			execve(path[i], options, NULL);
//	else
//		waitpid(pid, &status, 0);
//}

///**
// * This is the principal fonction in this file. It create a double char
// * **cmd_with_options (file:launch_cmd_bis.c) with the cmd and options.
// * The path is the env variable with the cmd in the end (file:launch_cmd_bis.c).
// * Then we check the list if there is a file in it or not (file:launch_cmd_bis.c)
// * and we use the good fonction
// * @param env
// *
// * @return void
// */
//void	ft_exec_cmd(t_env *env)
//{
//	t_token	*tmp;
//	char	**cmd_with_options;
//	char	**path;
//	int		i;
//
//	printf("exec cmd\n");
//	i = 0;
//	tmp = env->token;
//	cmd_with_options = tab_with_cmd_and_options(tmp);
//	path = ft_create_path_for_execve(env->envp, cmd_with_options[0]);
//	if (search_e_file_in_list(tmp) == 1)
//		launch_cmd_if_file_in_list(tmp, path, cmd_with_options, i);
//	else
//		launch_cmd_without_file(path, cmd_with_options, i);
//}
