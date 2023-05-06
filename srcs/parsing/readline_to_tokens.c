/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_to_tab_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:49:05 by synicole          #+#    #+#             */
/*   Updated: 2023/04/10 12:49:06 by synicole         ###   ########.fr       */
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
	int		i;

	i = 0;
	env->token = ft_new_token(tab[i]);
	i++;
	while (tab[i])
	{
		ft_add_token_end(&env->token, ft_new_token(tab[i]));
		i++;
	}
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

	split_space_tab = ft_split_token(ft_trim_str(readline));
	ft_array_to_token(split_space_tab, env);
}
