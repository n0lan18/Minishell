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
 * Get the number of a tab.
 * @param char *str
 *
 * @return int
 */
static int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/**
 * Check if str contains only number.
 * @param char *str
 *
 * @return int
 */
static int	ft_contains_only_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Executes the exit command.
 * 1. Check if no option
 * 2. Check if more than 1 option
 * 3. Check if option[1] contains only number
 *
 * @param void
 *
 * @return void
 */
int	ft_exec_exit(char **option)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (!option[1])
	{
		clear_history();
		exit(EXIT_SUCCESS);
	}
	if (ft_size_tab(option) > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		g_last_exit_code = 1;
		return (1);
	}
	if (!ft_contains_only_number(option[1]))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(option[0], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		clear_history();
		exit(255);
	}
	clear_history();
	exit(ft_atoi(option[1]));
}
