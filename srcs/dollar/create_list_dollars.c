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

/**
 * TODO
 *
 * @param list
 * @param str
 * @param i
 *
 * @return void
 */
void	ft_create_list_dollars(t_dollar **list, const char *str)
{
	t_dollar	*dollar;
	int			j;
	int			i;
	char		*substring;

	i = 0;
	while (str[i])
	{
		j = i;
		while (str[i] && str[i] != '$')
			i++;
		if (i > j)
		{
			substring = ft_substr(str, j, i - j);
			dollar = ft_new_dollar(substring);
			free(substring);
			ft_add_dollar_end(list, dollar);
		}
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
			{
				substring = ft_substr(str, i, 2);
				dollar = ft_new_dollar(substring);
				free(substring);
				ft_add_dollar_end(list, dollar);
				i += 2;
				continue ;
			}
			j = i + 1;
			while (str[j] && ft_valid_identifier(str[j]))
				j++;
			substring = ft_substr(str, i, j - i);
			dollar = ft_new_dollar(substring);
			free(substring);
			ft_add_dollar_end(list, dollar);
			i = j;
		}
		else
			i++;
	}
}
