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
static void	ft_tab_to_tokens(char **tab, t_token **list)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		*list = ft_add_new_token(*list, tab[i]);
		i++;
	}
}

/**
 * Converts a string input to an array of tokens
 * @param char *readline to be converted to tokens
 *
 * @return A pointer to the first token, or NULL if no tokens were created
*/
t_token	*ft_readline_to_tokens(char *readline)
{
	char	**split_space_tab;
	t_token	*tokens;

	tokens = NULL;
	split_space_tab = ft_split_tokens(ft_trim_str(readline));
	ft_tab_to_tokens(split_space_tab, &tokens);
	ft_assign_type_for_each_token(tokens);
	return (tokens);
}
