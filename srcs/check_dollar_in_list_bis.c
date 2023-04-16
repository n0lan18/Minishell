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

int	search_dollar_in_list(t_list *list)
{
	t_list	*tmp;
	t_param	inc;

	tmp = list;
	inc.i = 0;
	inc.num = 0;
	while (tmp)
	{
		if (tmp->str[0] == 39)
		{
			tmp = tmp->next;
			while (tmp && tmp->str[0] != 39)
				tmp = tmp->next;
		}
		if (tmp->str[0] == '$' && tmp->next->str[0] != ' ')
			inc.num -= 1;
		tmp = tmp->next;
	}
	return (0);
}

char	*add_var_and_word(char *str, char *str1, char *tab)
{
	t_param	inc;

	inc.str = NULL;
	inc.i = 0;
	inc.j = 0;
	inc.x = -1;
	if (str1 == NULL)
	{
		tab = "sdiuhsidhisd";
		return (tab);
	}
	inc.str = ft_strcpy_new(inc.str, tab, 0, ft_strlen(tab));
	free(str);
	while (str1[inc.j])
		inc.j++;
	tab = malloc(sizeof(char) * (inc.i + inc.j) + 1);
	if (!tab)
		return (NULL);
	while (++inc.x < inc.i)
		tab[inc.x] = inc.str[inc.x];
	inc.j = 0;
	while (str1[inc.j])
		tab[inc.x++] = str1[inc.j++];
	tab[inc.x] = '\0';
	return (tab);
}

char	*search_var_in_env(char *str, char **env)
{
	t_param	inc;

	inc.i = 0;
	inc.j = 0;
	inc.deb = 0;
	inc.x = ft_strlen(str) - 1;
	while (env[inc.i])
	{
		inc.x = ft_strlen(str) - 1;
		if (ft_strncmp(str, env[inc.i], inc.x) == 0
			&& env[inc.i][inc.x + 1] == '=')
		{
			inc.x++;
			inc.deb = inc.x + 1;
			while (env[inc.i][inc.x])
				inc.x++;
			str = ft_strcpy_new(str, env[inc.i], inc.deb, inc.x);
			return (str);
		}
		inc.i++;
	}
	return (NULL);
}
