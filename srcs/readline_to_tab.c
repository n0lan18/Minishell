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

t_list	*split_new_format(t_list *liste, char *str, int i, int j, t_param inc)
{
	t_list *tmp;

	tmp = liste;
	while (i <= j)
	{
		while (str[i] == ' ' && i <= j)
			i++;
		inc.deb = i;
		if (str[inc.deb] == '$')
		{
			while ((str[i + 1] != '$' && i <= j))
				i++;
		}
		else if (str[inc.deb] == '"' || str[inc.deb] == 39)
			i++;
		else
		{
			while (str[i] != ' ' && i <= j)
				i++;
			i--;
		}
		tmp = add_new_element(tmp, str, inc.deb, i);
		printf("%s\n", tmp->str);
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

t_list 	*readline_to_tab(char *readline, t_list *liste)
{
	t_param inc;
	t_list *tmp;

	inc.i = 0;
	inc.j = ft_strlen(readline) - 1;
	tmp = liste;
	while (readline[inc.i] && readline[inc.i] == ' ')
		inc.i++;
	while (inc.j >= 0 && readline[inc.j] == ' ')
		inc.j--;
	tmp = split_new_format(tmp, readline, inc.i, inc.j, inc);
	while (tmp)
	{
		printf("liste %s\n", tmp->str);
		tmp = tmp->next;
	}
    return (liste);
}