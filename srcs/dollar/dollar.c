/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:15:22 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 22:15:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_dollar(t_env *env)
{
	t_token	*start;

	start = env->token;
	while (env->token)
	{
		env->token = env->token->next;
	}
	env->token = start;
}
