/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:09:51 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/26 16:33:23 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	check_if_var_exist(t_token *env, char *str)
{
	t_token	*tmp;
	t_token	*temp;
	int		i;

	tmp = env;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	while (tmp)
	{
		if (ft_strncmp(tmp->str, str, i) == 0)
		{
			temp->next = tmp->next;
			free(tmp);
		}
		temp = tmp;
		tmp = tmp->next;
	}
}

static char	*join_var(t_token *list)
{
	t_token	*tmp;
	char	*join;

	tmp = list;
	while (tmp)
	{
		if (tmp->str[0] != ' ')
		{
			join = list->str;
			tmp = tmp->next;
			while (tmp)
			{
				if (tmp->str[0] == ' ')
					return (join);
				join = ft_strjoin(join, tmp->str);
				if (tmp->next == NULL)
					return (join);
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return (join);
}

static int	check_if_var_is_good(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

static int	check_after_equal(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			num++;
		if (str[i] != ' ')
		{
			num *= -1;
			break ;
		}
		i++;
	}
	return (num);
}

void	ft_run_export(t_token *env, t_token *list)
{
	t_token	*tmp;
	char	*str;

	tmp = list;
	tmp = tmp->next;
	tmp = tmp->next;
	if (check_if_var_is_good(tmp->str) == 0)
	{
		if (tmp->next == NULL)
			str = tmp->str;
		else
			str = join_var(tmp);
		if (check_after_equal(str) >= 0)
		{
			check_if_var_exist(env, str);
			add_element(env, str);
		}
		else
		{
			check_if_var_exist(env, str);
			add_element(env, "💩");
		}
	}
}
