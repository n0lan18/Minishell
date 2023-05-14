/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:23:53 by synicole          #+#    #+#             */
/*   Updated: 2023/05/14 16:23:54 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print_cmd_not_found(char *cmd_name)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd_name, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

void	ft_print_not_a_valid_identifier(char *str, char *builtin_name)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(builtin_name, STDERR_FILENO);
	ft_putstr_fd(": `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}
