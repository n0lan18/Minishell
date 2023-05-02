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
 * Initializes an array of tokens from a string array
 * @param char **tab containing individual tokens
 * @param t_token **tokens a pointer to the first element in the token array
 *
 * @return void
*/
static void	ft_init_tokens(char **tab, t_token **list)
{
	int		i;
	int		j;
	char	**tab_trimmed;

	i = 0;
	while (tab[i])
	{
		j = 0;
		tab_trimmed = ft_split_in_ft_split(tab[i]);
		while (tab_trimmed[j])
			*list = ft_add_new_token(*list, tab_trimmed[j++]);
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
	split_space_tab = ft_split_space(ft_trim_str(readline));
	db_print_tab(split_space_tab);
	ft_init_tokens(split_space_tab, &tokens);
	return (tokens);
}
