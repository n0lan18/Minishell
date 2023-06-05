/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:59:09 by synicole          #+#    #+#             */
/*   Updated: 2023/06/05 20:59:11 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Free the t_dollar structure.
 *
 * @param env
 *
 * @return void
 */
void	ft_free_dollar(t_dollar *dollar)
{
	t_dollar	*tmp;

	while (dollar)
	{
		tmp = dollar;
		dollar = dollar->next;
		free(tmp->str);
		free(tmp);
	}
}
