/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:47:17 by synicole          #+#    #+#             */
/*   Updated: 2023/05/23 11:29:20 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_len_option(char **option)
{
	int	len;

	len = 0;
	while (option[len])
		len++;
	return (len);
}

static char	**ft_get_option(char **option, char **option_tmp)
{
	size_t	i;

	i = 0;
	while (option_tmp[i] != NULL)
	{
		option[i] = option_tmp[i];
		i++;
	}
	return (option);
}

char	**ft_get_cmd_option(t_token **current, t_cmd *cmd)
{
	size_t	i;
	char	*option_tmp[1024];
	char	**option;

	i = 1;
	cmd->name = (*current)->str;
	option_tmp[0] = cmd->name;
	(*current) = (*current)->next;
	while ((*current) != NULL)
	{
		if ((*current)->type == E_PIPE || (*current)->type == E_REDIRECTION)
			break ;
		else if ((*current)->type == E_STRING && (*current)->show)
		{
			option_tmp[i] = (*current)->str;
			i++;
		}
		if ((*current) != NULL)
			(*current) = (*current)->next;
	}
	option_tmp[i] = NULL;
	option = ft_calloc(sizeof(char *), ft_len_option(option_tmp) + 1);
	option = ft_get_option(option, option_tmp);
	return (option);
}
