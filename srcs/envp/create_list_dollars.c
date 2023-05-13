/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_dollars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:03:44 by synicole          #+#    #+#             */
/*   Updated: 2023/05/10 01:03:46 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_create_list_dollars(t_dollar **list, const char *str, int i)
{
	t_dollar	*dollar;
	int			j;

	while (str[i])
	{
		j = i;
		while (str[i] && str[i] != '$')
			i++;
		if (i > j)
		{
			dollar = ft_new_dollar(ft_substr(str, j, i - j));
			ft_add_dollar_end(list, dollar);
		}
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
			{
				dollar = ft_new_dollar(ft_substr(str, i, 2));
				ft_add_dollar_end(list, dollar);
				i += 2;
				continue ;
			}
			j = i + 1;
			while (str[j] && ft_valid_identifier(str[j]))
				j++;
			dollar = ft_new_dollar(ft_substr(str, i, j - i));
			ft_add_dollar_end(list, dollar);
			i = j;
		}
		else
			i++;
	}
}
