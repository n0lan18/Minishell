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

int	search_in_str(char s, char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == s)
			return (1);
		j++;
	}
	return (0);
}

int	count_word(const char *s, char c, int deb, int end)
{
	int	i;
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

int	count_word_fort_second_split(const char *s)
{
	t_param	inc;

	inc.num = 0;
	inc.i = 0;
	inc.deb = 0;
	while (s[inc.i] != '$' && s[inc.i] != '>' && s[inc.i] != '<' && \
		s[inc.i] != '"' && s[inc.i] != '|' && s[inc.i] != 39 && s[inc.i])
		inc.i++;
	if (inc.i > inc.deb)
		inc.num++;
	inc.num = count_word_fort_second_split_bis(s, inc.num, inc.i);
	return (inc.num);
}

int	count_word_fort_second_split_bis(const char *s, int num, int i)
{
	while (s[i])
	{
		if (s[i] == '$' || s[i] == '>' || s[i] == '<' \
				|| s[i] == '"' || s[i] == '|' || s[i] == 39)
		{
			if (s[i + 1] == '$' || s[i + 1] == '>'
				|| s[i + 1] == '<' || s[i + 1] == '"'
				|| s[i + 1] == '|' || s[i + 1] == 39 \
				||s[i + 1] == '\0')
				num++;
			else
				num += 2;
		}
		i++;
	}
	return (num);
}

int	remove_space_begin_or_end(char *str, int pos)
{
	int	i;

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