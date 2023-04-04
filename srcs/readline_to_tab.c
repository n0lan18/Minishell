/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:36:46 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/03 10:31:49 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_words(char *readline, int i, int j, t_param inc)
{
	inc.num = 1;
	while (i <= j)
	{
        if (readline[i] == ' ' && readline[i])
        {
            inc.num++;
            i++;
            while (readline[i] == ' ' && readline[i])
                i++;
        }
        if (readline[i] == '"' || readline[i] == 39)
        {
            i++;
            if (readline[i] == '"')
                while (readline[i] != '"' && readline[i])
                    i++;
            if (readline[i] == 39)
                while (readline[i] != 39 && readline[i])
                    i++;
        }
        i++;
	}
	return (inc.num);
}

char	*ft_strcpy_new_format(char *dst, char *str, int deb, int end)
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

char	**split_new_format(char	**tab, char *str, int i, int j, t_param inc)
{
    inc.deb = i;
    inc.y = -1;
    while (i <= j)
    {
        while (str[i] == ' ' && i <= j)
            i++;
        if (str[i] != ' ')
        {
            inc.deb = i;
            i++;
            if (str[inc.deb] == '"')
                while (str[i] != '"' && i <= j)
                    i++;
            else if (str[inc.deb] == 39)
                while (str[i] != 39 && i <= j)
                    i++;
            else
                while (str[i + 1] != ' ' && i <= j)
                    ++i;
            tab[++inc.y] = ft_strcpy_new_format(*tab, str, inc.deb, i);
        }
        i++;
    }
    tab[++inc.y] = NULL;
    return (tab);
}

char	**readline_to_tab(char *readline)
{
	char	**tab;
	t_param inc;

	inc.i = 0;
	inc.j = ft_strlen(readline) - 1;
	while (readline[inc.i] && readline[inc.i] == ' ')
		inc.i++;
	while (inc.j >= 0 && readline[inc.j] == ' ')
		inc.j--;
	tab = malloc(sizeof(char *) * count_words(readline, inc.i, inc.j, inc) + 1);
    if (!tab)
        return (NULL);
	tab = split_new_format(tab, readline, inc.i, inc.j, inc);
    return (tab);
}
