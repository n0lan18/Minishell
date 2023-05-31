/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_to_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:49:05 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 17:32:35 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Convert a string array to an array of tokens
 * @param char **tab containing individual tokens
 * @param t_token **tokens a pointer to the first element in the token array
 *
 * @return void
*/
static void	ft_array_to_token(char **tab, t_env *env)
{
	int	i;

	env->token = ft_new_token(tab[0]);
	i = 1;
	while (tab[i])
	{
		ft_add_token_end(&env->token, ft_new_token(tab[i]));
		i++;
	}
	ft_free_tab(tab);
}

/**
 * Converts a string input to an array of tokens
 * @param char *readline to be converted to tokens
 *
 * @return void
*/
void	ft_readline_to_token(t_env *env, char *readline)
{
	char	**split_space_tab;
	char	*trimmed;

	trimmed = ft_trim_str(readline);
	split_space_tab = ft_split_token(trimmed);
	free(trimmed);
	ft_array_to_token(split_space_tab, env);
	ft_add_token_previous(env->token);
}
