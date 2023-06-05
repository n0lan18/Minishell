/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:23:50 by synicole          #+#    #+#             */
/*   Updated: 2023/06/04 20:23:51 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
