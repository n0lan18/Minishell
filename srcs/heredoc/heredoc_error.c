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

/**
 * Display the error message for the heredoc.
 *
 * @param env
 *
 * @return void
 */
void	ft_heredoc_error(t_env *env)
{
	ft_putstr_fd("minishell: syntax error near unexpected token", 2);
	ft_putstr_fd(" `newline'\n", 1);
	env->syntax_error_type = E_SYNTAX_HEREDOC;
	g_last_exit_code = 258;
}
