/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:36:46 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/05 15:06:37 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int search_in_str(char s, char *str)
{
	int j;

	j = 0;
	while (str[j])
	{
		if (str[j] == s)
			return (1);
		j++;
	}
	return (0);
}

int 	count_word(const char *s, char c, int deb, int end)
{
	int 	i;
	int	size;
	int	start;

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
			size++;
	}
	return (size);
}

int 	count_word_fort_second_split(const char *s)
{
	t_param inc;

	inc.num = 0;
	inc.i = 0;
	inc.deb = 0;
	while (s[inc.i] != '$' && s[inc.i] != '>' && s[inc.i] != '<' && \
		s[inc.i] != '"' && s[inc.i] != '|' && s[inc.i] != 39 && s[inc.i])
		inc.i++;
	if (inc.i > inc.deb)
		inc.num++;
	while (s[inc.i])
	{
		if (s[inc.i] == '$' || s[inc.i] == '>' || s[inc.i] == '<' \
				|| s[inc.i] == '"' || s[inc.i] == '|' || s[inc.i] == 39)
		{
			if (s[inc.i + 1] == '$' || s[inc.i + 1] == '>' || s[inc.i + 1] == '<' \
				|| s[inc.i + 1] == '"' || s[inc.i + 1] == '|' \
				|| s[inc.i + 1] == 39 || s[inc.i + 1] == '\0')
				inc.num++;
			else
				inc.num += 2;
		}
		inc.i++;
	}
	return (inc.num);
}

char	**ft_split_next_gen(char const *s, char c, int deb, int end)
{
	char	**tab;
	int	size;
	int	start;
	int	i;

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
	t_param a;

	a.i = 0;
	a.j = 0;
	a.deb = 0;
	a.tab = malloc(sizeof(char *) * count_word_fort_second_split(s) + 1);
	if (!a.tab)
		return (NULL);
	while (s[a.i])
	{
		if (s[a.i] == '$' || s[a.i] == '>' || s[a.i] == '<' \
		|| s[a.i] == '"' || s[a.i] == '|' || s[a.i] == 39 || s[a.i] == '\0')
		{
			a.tab[a.j++] = ft_strcpy_new(a.tab[a.j], (char *) s, a.i, a.i);
			a.deb = a.i + 1;
		}
		else if (s[a.i + 1] == '$' || s[a.i + 1] == '>' || s[a.i + 1] == '<' \
		|| s[a.i + 1] == '"' || s[a.i + 1] == '|' || s[a.i + 1] == 39 || s[a.i + 1] == '\0')
		{
			a.tab[a.j++] = ft_strcpy_new(a.tab[a.j], (char *) s, a.deb, a.i);
			a.deb = a.i;
		}
		a.i++;
	}
	return (a.tab);
}

char	*ft_strcpy_new(char *dst, char *str, int deb, int end)
{
	int	i;

	i = 0;
	dst = malloc(sizeof(char) * (end - deb) + 1);
	if (!dst)
		return (NULL);
	while (deb <= end)
		dst[i++] = str[deb++];
	dst[i] = '\0';
	return (dst);
}

t_list	*split_new_format(char *rline, t_list *liste)
{
	t_param inc;
	char **tab;
	char **tab1;
	t_list	*tmp;

	inc.i = 0;
	inc.deb = remove_space_begin_or_end(rline, 0);
	inc.y = remove_space_begin_or_end(rline, 1);
	tmp = liste;
	tab = ft_split_next_gen(rline, ' ', inc.deb, inc.y);
	while (tab[inc.i])
	{
		inc.j = 0;
		inc.x = 0;
		tab1 = ft_split_in_ft_split(tab[inc.i]);
		while (tab1[inc.j])
			inc.j++;
		while (inc.x < inc.j)
			tmp = add_new_element(tmp, tab1[inc.x++]);
		free_double_tab(tab1);
		inc.i++;
	}
	free_double_tab(tab);
	return (tmp);
}

int remove_space_begin_or_end(char *str, int pos)
{
	int i;

	if (pos == 0)
	{
		i = 0;
		while (str[i] && str[i] == ' ')
			i++;
		return (i);
	}
	else
	{
		i = (int)ft_strlen(str) - 1;
		while (i >= 0 && str[i] == ' ')
			i--;
		return (i);
	}
}