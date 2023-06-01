/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:09:48 by synicole          #+#    #+#             */
/*   Updated: 2023/05/31 16:09:50 by synicole         ###   ########.fr       */
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
//		free(tmp->str);
		free(tmp);
	}
}
