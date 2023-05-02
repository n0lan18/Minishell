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

//t_token	*hey_follow_tmp(t_token *list, char c, int num)
//{
//	if (c == 39 || (c == '"' && num > 0))
//	{
//		list = list->next;
//		if (list->str[0] == c)
//		{
//			list = list->next;
//			return (list);
//		}
//		while (list->next && list->str[0] != c)
//			list = list->next;
//		list = list->next;
//	}
//	else if (c == ' ' || c == '$' || c == '"')
//		list = list->next;
//	else
//	{
//		while (list)
//		{
//			if (list->str[0] == '"' || list->str[0] == 39 || \
//			list->str[0] == ' ' || list->str[0] == '$')
//				break ;
//			list = list->next;
//		}
//	}
//	return (list);
//}
//
//t_token	*rewrite_bis(t_token *tmp, t_token *new, char c, int num)
//{
//	char	*str;
//
//	str = NULL;
//	if (c == ' ' || c == '$' || (c == '"' && num == 0))
//			new = add_new_element(new, tmp->str);
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
//		new = add_new_element(new, str);
//	}
//	free(str);
//	return (new);
//}
//
//t_token	*rewrite_bis_bis(t_token *tmp, t_token *new)
//{
//	char	*str;
//
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
//	new = add_new_element(new, str);
//	return (new);
//}
//
//t_token	*rewrite(t_token *list, int num)
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
//			new = add_new_element(new, t->str);
//			break ;
//		}
//		if (t->str[0] == '"' || t->str[0] == 39 || \
//		t->str[0] == 36 || t->str[0] == 32)
//			new = rewrite_bis(t, new, t->str[0], num);
//		else
//			new = rewrite_bis_bis(t, new);
//		t = hey_follow_tmp(t, t->str[0], num);
//	}
//	free_list(list);
//	return (new);
//}
//
//t_token	*good_parse(t_token *list, t_token *env)
//{
//	list = rewrite(list, 0);
//	list = replace_if_dollar(list, env);
//	list = rewrite(list, 1);
//	list = together_if_not_space(list);
//	return (list);
//}
