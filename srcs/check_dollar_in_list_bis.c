/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollar_in_list_bis.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:03:33 by synicole          #+#    #+#             */
/*   Updated: 2023/04/29 00:09:23 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*add_var_and_word(char *str, const char *str1, char *tab)
{
	t_param	inc;

	inc.str = NULL;
	inc.i = 0;
	inc.j = 0;
	inc.x = -1;
	if (str1 == NULL)
	{
		tab = "💩";
		return (tab);
	}
	inc.str = ft_strcpy_new(inc.str, tab, 0, (int)ft_strlen(tab));
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

char	*search_var_in_env(char *str, t_token *env)
{
	int		start;
	int		len;
	t_token	*tmp;

	tmp = env;
	while (tmp)
	{
		len = compare_length_in_env(tmp->str);
		if (ft_strncmp(str, tmp->str, ft_strlen(str)) == 0)
		{
			start = len + 1;
			while (tmp->str[len])
				len++;
			str = ft_strcpy_new(str, tmp->str, start, len);
			return (str);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	compare_length_in_env(const char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}
