/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_type_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:14:17 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/10 19:04:33 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Fonction who check if case of list is space
 * @param s 
 * @return int 
 */
static int	is_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/**
 * Give type in all cases of t_token struct
 * @param str 
 * @param token 
 * @param envp 
 * @return int 
 */
static int	search_which_type(char *str, t_token *token, t_envp *envp)
{
	if ((ft_strncmp(str, "echo", 5) == 0)
		|| (ft_strncmp(str, "cd", 3) == 0)
		|| (ft_strncmp(str, "export", 7) == 0)
		|| (ft_strncmp(str, "pwd", 4) == 0)
		|| (ft_strncmp(str, "env", 4) == 0)
		|| (ft_strncmp(str, "unset", 6) == 0)
		|| (ft_strncmp(str, "exit", 5) == 0))
		token->type = E_BUILTIN;
	else if (ft_strncmp(str, "|", ft_strlen(str)) == 0)
		token->type = E_PIPE;
	else if (is_space(str))
		token->type = E_SPACE;
	else if ((ft_strncmp(str, ">", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "<", ft_strlen(str)) == 0))
		token->type = E_REDIRECTION;
	else if (search_of_type_cmd(envp, str) == 0)
		token->type = E_CMD;
	else if (open(str, O_RDONLY) != -1)
	{
		token->type = E_FILE;
		close(open(str, O_RDONLY));
	}
	else
		token->type = E_STRING;
	return (token->type);
}

/**
 * Init type in all case of env->token
 * @param token
 * @param env
 * 
 * @return void
 */
void	init_type_in_list(t_env *env)
{
	t_token	*tmp;
	t_envp	*tmp_env;

	tmp = env->token;
	tmp_env = env->envp;
	while (tmp)
	{
		tmp->type = search_which_type(tmp->str, tmp, tmp_env);
		tmp = tmp->next;
	}
}