/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollar_in_list_bis.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:03:33 by synicole          #+#    #+#             */
/*   Updated: 2023/04/10 12:03:36 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*check_if_dollar(t_list *list, char **env)
{
	t_list	*tmp;
	t_param	inc;
	char	*str;
	char	*str1;

	tmp = list;
	inc.i = 0;
	inc.deb = 0;
	if (search_quote_in_list(tmp) == 1)
		return (list);
	while (tmp)
	{
		while (tmp->str[inc.i])
		{
			if (tmp->str[inc.i] == '$')
			{
				inc.deb = inc.i + 1;
				while (tmp->str[inc.i] && tmp->str[inc.i + 1] != ' ')
					inc.i++;
				str = ft_strcpy(str, tmp->str, inc.deb, inc.i);
				printf("STR %s\n", str);
				str1 = search_var_in_env(str, env);
				tmp->str = add_var_and_word(str, str1, tmp->str);
				break ;
			}
			inc.i++;
		}
		tmp = tmp->next;
		inc.i = 0;
	}
	return (list);
}

int	check_many_dollar_in_str(char *str)
{
	t_param	inc;

	inc.i = 0;
	inc.num = 0;
	while (str[inc.i] && str[inc.i] != ' ')
	{
		if (str[inc.i] == '$')
			inc.num++;
		inc.i++;
	}
	return (inc.num);
}
