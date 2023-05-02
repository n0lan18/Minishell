/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:19:35 by synicole          #+#    #+#             */
/*   Updated: 2023/04/28 12:19:37 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**token_to_char(t_token *env)
{
	char	**envp;
	t_token	*tmp;
	int		i;

	envp = malloc(sizeof(char) * (size_list(env) + 1));
	if (!envp)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		envp[i] = tmp->str;
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

char	*ft_strcpy_new(char *dst, char *str, int deb, int end)
{
	int	i;

	i = 0;
	if ((end - deb) == 0)
		dst = malloc(sizeof(char) * 2);
	else
		dst = malloc(sizeof(char) * (end - deb) + 2);
	if (!dst)
		return (NULL);
	while (deb <= end)
		dst[i++] = str[deb++];
	dst[i] = '\0';
	return (dst);
}