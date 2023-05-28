/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 08:29:33 by synicole          #+#    #+#             */
/*   Updated: 2023/05/27 08:29:34 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_heredoc_error(int code_error)
{
	if (code_error == 1)
		ft_putstr_fd("minishell: parse error near <<\n", 2);
	else
	{
		ft_putstr_fd("minishell: syntax error near unexpected token", 2);
		ft_putstr_fd(" `newline'\n", 1);
	}
	g_last_exit_code = 258;
	return (1);
}

int	ft_heredoc_error_eof(const char *str)
{
	if (*str == '#')
		return (1);
	return (0);
}