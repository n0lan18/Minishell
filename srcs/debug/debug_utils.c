/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:54:47 by synicole          #+#    #+#             */
/*   Updated: 2023/05/02 14:54:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Prints the content of a char **tab.
 * @param char **tab
 *
 * @return void
*/
void	db_print_tab(char **tab)
{
	int	i;

	printf("\n--- DEBUG: PRINT TAB ---\n");
	i = 0;
	while (tab[i])
		printf("[%s]\n", tab[i++]);
	printf("\n");
}

/**
 * Prints the content of a token.
 * @param t_token *token
 *
 * @return void
*/
void	db_print_token(t_token *token)
{
	t_token	*current;

	printf("\n--- DEBUG: PRINT TOKEN ---\n");
	printf("--------------------------------\n");
	current = token;
	while (current)
	{
		printf("[%s] <= token\n", current->str);
		printf("{%d} <= type\n", current->type);
		printf("{%d} <= quote\n", current->quote);
		printf("{%d} <= redirection\n", current->redirection);
		printf("--------------------------------\n");
		current = current->next;
	}
	printf("\n");
}

/**
 * Prints the content of a t_cmd.
 * @param t_cmd *cmd
 *
 * @return void
*/
void	db_print_cmd(t_cmd *cmd)
{
	t_cmd	*current;
	int		i;

	i = 0;
	printf("\n--- DEBUG: PRINT COMMAND ---\n");
	printf("--------------------------------\n");
	current = cmd;
	while (current)
	{
		printf("[%s] <= name\n", current->name);
		if (current->option)
		{
			while (current->option[i])
			{
				printf("[%s] <= option[%d]\n", current->option[i], i);
				i++;
			}
		}
		i = 0;
		printf("[%d] <= fd_read\n", current->fd_read);
		printf("[%d] <= fd_write\n", current->fd_write);
		printf("--------------------------------\n");
		current = current->next;
	}
	printf("\n");
}

/**
 * Prints the content of a t_env.
 * @param t_env *env
 *
 * @return void
*/
void	db_print_envp(t_envp *envp)
{
	t_envp	*current;

	printf("\n--- DEBUG: PRINT ENVP ---\n");
	current = envp;
	while (current)
	{
		printf("(NAME)[%s] -> (VALUE)[%s]\n",
			current->name, current->value);
		current = current->next;
	}
	printf("\n");
}

/**
 * Prints the content of a t_dollar.
 * @param t_dollar *dollar
 *
 * @return void
*/
void	db_print_dollar(t_dollar *dollar)
{
	t_dollar	*current;

	printf("\n--- DEBUG: PRINT DOLLAR ---\n");
	current = dollar;
	while (current)
	{
		printf("(STR)[%s]\n", current->str);
		current = current->next;
	}
	printf("\n");
}
