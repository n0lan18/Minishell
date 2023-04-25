/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:23:50 by synicole          #+#    #+#             */
/*   Updated: 2023/04/10 11:23:53 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*prompt_output;
	t_token	*list;
	t_token	*env;

	(void)argc;
	(void)argv;
	list = NULL;
	env = NULL;
	env = env_in_list(envp, env);
	prompt_output = "";
	while (prompt_output != NULL)
	{
		ft_init_signals();
		prompt_output = readline("minishell-1.0$ ");
		if (!prompt_output)
			ft_close();
		list = split_new_format(prompt_output, list);
		list = replace_if_dollar(list, env);
		if (list)
		{
			init_type_in_list(list, env);
			check_if_built(list, env);

			char* cmd = list->str;
			char* cmd_path = NULL;

			// Recherche du chemin absolu de la commande
			for (int i = 0; envp[i] != NULL; i++) {
				char* var = envp[i];
				if (strncmp(var, "PATH=", 5) == 0) {
					char* path = var + 5;
					char* path_copy = strdup(path);
					char* dir = strtok(path_copy, ":");
					while (dir != NULL) {
						char* tmp_path = malloc(strlen(dir) + strlen(cmd) + 2);
						sprintf(tmp_path, "%s/%s", dir, cmd);
						if (access(tmp_path, X_OK) == 0) {
							cmd_path = tmp_path;
							break;
						}
						free(tmp_path);
						dir = strtok(NULL, ":");
					}
					free(path_copy);
					if (cmd_path != NULL) {
						break;
					}
				}
			}

			pid_t pid = fork();
			if (pid == -1) {
				perror("fork");
				continue;
			}
			else if (pid == 0)
			{
				// Dans le processus enfant
				if (cmd_path == NULL)
				{
					printf("minishell: %s: command not found\n", cmd);
					exit(1); // Terminer le processus enfant avec un code d'erreur
				}

				// Arguments de la commande
				char* args[] = {cmd, NULL};

				// Exécution de la commande
				if (execve(cmd_path, args, envp) == -1)
				{
					perror("execve");
					exit(1); // Terminer le processus enfant avec un code d'erreur
				}
			}
			else {
				// Dans le processus parent

				// Attendre que le processus enfant se termine
				int status;
				waitpid(pid, &status, 0);

				// Vérifier le code de retour du processus enfant
				if (WIFEXITED(status)) {
					int exit_status = WEXITSTATUS(status);
					if (exit_status != 0) {
						printf("La commande a échoué avec le code %d\n",
							   exit_status);
					}
				} else if (WIFSIGNALED(status)) {
					int signal_number = WTERMSIG(status);
					printf("La commande a été interrompue par le signal %d\n",
						   signal_number);
				}
			}

			while (list)
			{
				printf("liste : %s\n", list->str);
				printf("type : %d\n", list->type);
				list = list->next;
			}
		}
		free_list(list);
		add_history(prompt_output);
	}
	return (0);
}
