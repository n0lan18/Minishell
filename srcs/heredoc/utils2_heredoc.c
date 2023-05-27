/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:03:49 by synicole          #+#    #+#             */
/*   Updated: 2023/05/27 09:03:51 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_heredoc_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*new_str;

	new_str = NULL;
	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		str = ft_memcpy(str, s1, ft_strlen(s1));
		free(s1);
	}
	new_str = ft_strjoin(str, s2);
	free(str);
	if (s2 != NULL)
		free(s2);
	return (new_str);
}

void	ft_heredoc_open2(char *all, t_env *env, int fd_heredoc, t_token *hd)
{
	if (hd->quote == E_NONE_QUOTE)
		ft_heredoc_replace_varenv(&all, env->envp);
	ft_putstr_fd(all, fd_heredoc);
	free(all);
}
