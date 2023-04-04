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


int search_quote_in_tab(char **tab)
{
    t_param inc;

    inc.i = 0;
    inc.j = 0;
    while (tab[inc.i])
    {
        while (tab[inc.i][inc.j])
        {
            if (tab[inc.i][inc.j] == 39)
                return(1);
            inc.j++;
        }
        inc.i++;
        inc.j = 0;
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
    free(tab);
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
        printf("%s\n", env[inc.i]);
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

char **check_if_dollar(char **tab, char **env, t_param inc)
{
    char *str;
    char *str1;

    inc.i = 0;
    inc.j = 0;
    inc.deb = inc.j;
    if (search_quote_in_tab(tab) == 1)
        return (tab);
    while (tab[inc.i])
    {
        while (tab[inc.i][inc.j])
        {
            if (tab[inc.i][inc.j] == '$')
            {
                inc.deb = inc.j + 1;
                while (tab[inc.i][inc.j] && tab[inc.i][inc.j + 1] != ' ')
                    inc.j++;
                str = ft_strcpy(str, tab[inc.i], inc.deb, inc.j);
                printf("%s\n", str);
                str1 = search_var_in_env(str, env);
                printf("%s\n", str1);
                tab[inc.i] = add_var_and_word(str, str1, tab[inc.i]);
            }
            inc.j++;
        }
        inc.j = 0;
        inc.i++;
    }
    return (tab);
}
/*
void    replace_dollar_per_var(char **tab, char *str, int i, int j)
{
    while()
}

void    check_which_type(char **tab, char **env)
{
    if (ft_strncmp(tab[0], "env", ft_strlen(tab[i])) == 0)

       if (ft_strncmp(tab[i], "echo", ft_strlen(tab[i])) == 0)
            num += 10;
    if (ft_strncmp(tab[i], "export", ft_strlen(tab[i])) == 0)
            num += 100;
        if (ft_strncmp(tab[i], "pwd", ft_strlen(tab[i])) == 0)
            num += 1000;
        if (ft_strncmp(tab[i], "unset", ft_strlen(tab[i])) == 0)
            num += 10000;
        if (ft_strncmp(tab[i], "cd", ft_strlen(tab[i])) == 0)
            num += 100000;
        if (ft_strncmp(tab[i], "|", ft_strlen(tab[i])) == 0)
            num += 1000000;
        if (search_of_type_cmd(env, tab[i]) == 0)
            num += 10000000;
    }
}
*/