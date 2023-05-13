/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:34:38 by synicole          #+#    #+#             */
/*   Updated: 2023/05/13 20:34:40 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Executes the exit command.
 * @param void
 *
 * @return void
 */
void	ft_exec_exit(void)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	clear_history();
	exit(EXIT_SUCCESS);
}
