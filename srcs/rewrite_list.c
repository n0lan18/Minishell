/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:48:40 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/29 01:27:20 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*hey_follow_tmp(t_token *list, char c, int num)
{
	if (c == 39 || (c == '"' && num > 0))
	{
		list = list->next;
		if (list->str[0] == c)
		{
			list = list->next;
			return (list);
		}
		while (list->next && list->str[0] != c)
			list = list->next;
		list = list->next;
	}
	else if (c == ' ' || c == '$' || c == '"')
		list = list->next;
	else
	{
		while (list)
		{
			if (list->str[0] == '"' || list->str[0] == 39 || \
			list->str[0] == ' ' || list->str[0] == '$')
				break ;
			list = list->next;
		}
	}
	return (list);
}

//t_token	*rewrite_bis(t_token *tmp, t_token *new, char c, int is_double_quote)
//{
//	char	*str;
//
//	printf("rewrite_bis\n");
//	str = NULL;
//	if (c == ' ' || c == '$' || (c == '"' && is_double_quote == 0))
//			new = ft_add_new_token(new, tmp->str);
//	else
//	{
//		tmp = tmp->next;
//		if (tmp->str[0] == c)
//			return (new);
//		str = ft_strcpy_new(str, tmp->str, 0, ft_strlen(tmp->str));
//		tmp = tmp->next;
//		while (tmp)
//		{
//			if (tmp->str[0] == c)
//				break ;
//			str = ft_strjoin(str, tmp->str);
//			tmp = tmp->next;
//		}
//		new = ft_add_new_token(new, str);
//	}
//	return (new);
//}

//t_token	*rewrite_bis_bis(t_token *tmp, t_token *new)
//{
//	char	*str;
//
//	printf("rewrite_bis_bis\n");
//	str = NULL;
//	str = tmp->str;
//	tmp = tmp->next;
//	while (tmp)
//	{
//		if (tmp->str[0] == 39 || tmp->str[0] == '"' || \
//		tmp->str[0] == ' ' || tmp->str[0] == '$')
//			break ;
//		str = ft_strjoin(str, tmp->str);
//		if (tmp->str[0] == 39 || tmp->str[0] == '"' || \
//		tmp->str[0] == ' ' || tmp->str[0] == '$')
//			break ;
//		tmp = tmp->next;
//	}
//	new = ft_add_new_token(new, str);
//	return (new);
//}

//t_token	*rewrite(t_token *list, int is_double_quote)
//{
//	t_token	*new;
//	t_token	*t;
//
//	t = list;
//	new = NULL;
//	while (t)
//	{
//		if (t == NULL || (t->str[0] == '"' && t->next == NULL) || \
//		(t->str[0] == 39 && t->next == NULL) || \
//		(t->str[0] == 32 && t->next == NULL))
//		{
//			printf("caca\n");
//			new = ft_add_new_token(new, t->str);
//			break ;
//		}
//		if (t->str[0] == '"' || t->str[0] == 39 || \
//		t->str[0] == 36 || t->str[0] == 32)
//			new = rewrite_bis(t, new, t->str[0], is_double_quote);
//		else
//			new = rewrite_bis_bis(t, new);
//		t = hey_follow_tmp(t, t->str[0], is_double_quote);
//	}
//	free_list(list);
//	return (new);
//}

/**
 * Cette fonction "rewrite" prend en entrée une liste de tokens (t_token) et
 * un entier (is_double_quote) qui est utilisé pour indiquer si les guillemets
 * doubles (") sont actuellement actifs ou non. Elle renvoie une nouvelle liste
 * de tokens qui a été modifiée par certaines règles de "réécriture".
 * La fonction parcourt chaque élément de la liste de tokens.
 * Si l'élément est un guillemet double ou simple, un dollar ($), ou un espace,
 * la fonction appelle la fonction auxiliaire "rewrite_bis" pour réécrire
 * l'élément et les éléments suivants de la liste en fonction de certaines
 * règles de réécriture.
 *
 * Si l'élément n'est pas un guillemet, un dollar ou un espace, la fonction
 * appelle la fonction auxiliaire "rewrite_bis_bis" pour réécrire l'élément
 * en fonction d'autres règles de réécriture.
 *
 * Enfin, la fonction "rewrite" renvoie la nouvelle liste de tokens
 * modifiée et supprime l'ancienne liste de tokens en appelant
 * la fonction "free_list".
 */
//t_token	*ft_apply_single_quote(t_token *list, int is_double_quote)
//{
//	t_token	*new;
//
//	new = NULL;
//	while (list)
//	{
//		if ((ft_is_quotes(list->str[0]) && list->next == NULL)
//			|| (ft_is_space(list->str[0]) && list->next == NULL))
//		{
//			new = ft_add_new_token(new, list->str);
//			break ;
//		}
//		if (ft_is_quotes(list->str[0]) || ft_is_space(list->str[0])
//			|| list->str[0] == '$')
//			new = rewrite_bis(list, new, list->str[0], is_double_quote);
//		else
//			new = rewrite_bis_bis(list, new);
//		list = hey_follow_tmp(list, list->str[0], is_double_quote);
//	}
//	free_list(list);
//	return (new);
//}

//t_token	*good_parse(t_token *list, t_token *env)
//{
//	(void)env;
//	list = rewrite(list, 0);
//	list = replace_if_dollar(list, env);
//	list = rewrite(list, 1);
//	list = ft_apply_single_quote(list, 1);
//	list = together_if_not_space(list);
//	return (list);
//}
