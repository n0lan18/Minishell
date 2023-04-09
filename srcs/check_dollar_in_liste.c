/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words_in_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:29 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/03 12:58:43 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int search_quote_in_liste(t_list *liste)
{
    t_list *tmp;
	t_param	inc;

	tmp = liste;
	inc.i = 0;
    while (tmp)
    {
        while (tmp->str[inc.i])
        {
            if (tmp->str[inc.i] == 39 && tmp->str[inc.i + 1] == '$')
                return(1);
            inc.i++;
        }
		inc.i = 0;
        tmp = tmp->next;
    }
    return (0);
}

char *ft_strcpy(char *dst, char *src, int deb, int end)
{
    int i;

    i = 0;
    dst = malloc(sizeof(char) * (end - deb) + 1);
    if (!dst)
        return (NULL);
    while (deb <= end)
        dst[i++] = src[deb++];
    dst[i] = '\0';
    return (dst);
}

char *add_var_and_word(char *str, char *str1, char *tab)
{
    t_param inc;
    char *tmp;

    tmp = NULL;
    inc.i = 0;
    inc.j = 0;
    inc.x = -1;
    tmp = ft_strcpy(tmp, tab, 0, ft_strlen(tab));
    free(str);
    while (tmp[inc.i] && tmp[inc.i] != '$')
        inc.i++;
    while (str1[inc.j])
        inc.j++;
    tab = malloc(sizeof(char) * (inc.i + inc.j) + 1);
    if (!tab)
        return (NULL);
    while (++inc.x < inc.i)
        tab[inc.x] = tmp[inc.x];
    inc.j = 0;
    while (str1[inc.j])
        tab[inc.x++] = str1[inc.j++];
    tab[inc.x] = '\0';
    return (tab);
}

char *search_var_in_env(char *str, char **env)
{
    t_param inc;

    inc.i = 0;
    inc.j = 0;
    inc.deb = 0;
    inc.x = ft_strlen(str) - 1;
    while (env[inc.i])
    {
		inc.x = ft_strlen(str) - 1;
        if (ft_strncmp(str, env[inc.i], inc.x) == 0 && env[inc.i][inc.x + 1] == '=')
        {
            inc.x++;
            inc.deb = inc.x + 1;
            while (env[inc.i][inc.x])
                inc.x++;
            str = ft_strcpy(str, env[inc.i], inc.deb, inc.x);
            return (str);
        }
        inc.i++;
    }
    return (NULL);
}

t_list *check_if_dollar(t_list *liste, char **env)
{
    t_list *tmp;
	t_param	inc;
	char *str;
	char *str1;

	tmp = liste;
	inc.i = 0;
	inc.deb = 0;
	if (search_quote_in_liste(tmp) == 1)
		return (liste);
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
    return (liste);
}

int check_many_dollar_in_str(char *str)
{
	t_param inc;

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