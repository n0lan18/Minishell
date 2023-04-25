/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_to_tab_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:49:05 by synicole          #+#    #+#             */
/*   Updated: 2023/04/10 12:49:06 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_split_next_gen(char const *s, char c, int deb, int end)
{
	char	**tab;
	int		size;
	int		start;
	int		i;

	tab = malloc(sizeof(char *) * (count_word(s, c, deb, end) + 1));
	if (!tab)
		return (NULL);
	size = 0;
	i = deb;
	while (i <= end)
	{
		start = i;
		if (s[i] == c)
			while (s[i] == c && s[i])
				i++;
		else
			while (s[i] != c && s[i])
				i++;
		if (start != i)
			tab[size++] = ft_substr(s, start, i - start);
	}
	tab[size] = NULL;
	return (tab);
}

char	**ft_split_in_ft_split(char const *s)
{
	t_param	a;

	a.i = 0;
	a.j = 0;
	a.deb = 0;
	a.tab = ft_split_in_ft_split_bis(s, a);
	return (a.tab);
}

char	**ft_split_in_ft_split_bis(char const *s, t_param a)
{
	a.tab = malloc(sizeof(char *) * count_word_fort_second_split(s) + 1);
	if (!a.tab)
		return (NULL);
	while (s[a.i])
	{
		if (s[a.i] == '$' || s[a.i] == '>' || s[a.i] == '<' \
		|| s[a.i] == '"' || s[a.i] == '|' || s[a.i] == 39 || s[a.i] == '\0')
		{
			a.tab[a.j] = ft_strcpy_new(a.tab[a.j], (char *) s, a.i, a.i);
			a.deb = a.i + 1;
			a.j++;
		}
		else if (s[a.i + 1] == '$' || s[a.i + 1] == '>' || s[a.i + 1] == '<' \
		|| s[a.i + 1] == '"' || s[a.i + 1] == '|' || s[a.i + 1] == 39 \
		|| s[a.i + 1] == '\0')
		{
			a.tab[a.j] = ft_strcpy_new(a.tab[a.j], (char *) s, a.deb, a.i);
			a.deb = a.i;
			a.j++;
		}
		a.i++;
	}
	a.tab[a.j] = NULL;
	return (a.tab);
}

char	*ft_strcpy_new(char *dst, char *str, int deb, int end)
{
	int	i;

	i = 0;
	if ((end - deb) == 0)
		dst = malloc(sizeof(char) * 2);
	else
		dst = malloc(sizeof(char) * (end - deb) + 2);
	if (!dst)
		return (NULL);
	while (deb <= end)
		dst[i++] = str[deb++];
	dst[i] = '\0';
	return (dst);
}

t_token	*split_new_format(char *rline, t_token *list)
{
	t_param	inc;
	char	**tab;
	char	**tab1;
	t_token	*tmp;

	inc.i = 0;
	inc.deb = remove_space_begin_or_end(rline, 0);
	inc.y = remove_space_begin_or_end(rline, 1);
	tmp = list;
	tab = ft_split_next_gen(rline, ' ', inc.deb, inc.y);
	while (tab[inc.i])
	{
		inc.j = 0;
		inc.x = 0;
		tab1 = ft_split_in_ft_split(tab[inc.i]);
		while (tab1[inc.x])
			tmp = add_new_element(tmp, tab1[inc.x++]);
		free_double_tab(tab1);
		inc.i++;
	}
	free_double_tab(tab);
	return (tmp);
}
