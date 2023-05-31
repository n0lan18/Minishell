/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:12:59 by synicole          #+#    #+#             */
/*   Updated: 2023/04/14 14:13:01 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Exits the program with the given status and message.
 *
 * @param int status
 * @param char *message
 *
 * @return void
 */
void	ft_exit(int status, char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(status);
}

/**
 * Closes the program.
 *
 * @param t_env *env
 *
 * @return int
 */
int	ft_close(t_env *env)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	ft_free_envp(env);
	clear_history();
	return (g_last_exit_code);
}
