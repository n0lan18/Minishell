/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:46:04 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/30 16:34:23 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Display the options of echo
 * If the option is -n, the newline is not displayed
 * While there are options, display them and add a space between them
 *
 * @param char **option
 *
 * @return void
 */
void	ft_exec_echo(char **option)
{
	int	i;
	int	has_newline;

	i = 1;
	has_newline = 1;
	while (option[i] && ft_strncmp(option[i], "-n", 1) == 0)
	{
		has_newline = 0;
		i++;
	}
	while (option[i])
	{
		ft_putstr_fd(option[i], 1);
		if (option[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (has_newline)
		ft_putchar_fd('\n', 1);
}
