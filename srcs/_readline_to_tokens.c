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

#include "../minishell.h"

/**
 * Initializes an array of tokens from a string array
 * @param char **tab containing individual tokens
 * @param t_token **tokens a pointer to the first element in the token array
 *
 * @return void
*/
static void	ft_init_tokens(char **tab, t_token **tokens)
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
			*tokens = add_new_element(*tokens, tab_trimmed[j++]);
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
	int		start;
	int		end;
	char	**tab_without_space;
	t_token	*tokens;

	tokens = NULL;
	start = remove_space_begin_or_end(readline, 0);
	end = remove_space_begin_or_end(readline, 1);
	tab_without_space = ft_split_next_gen(readline, ' ', start, end);
	ft_init_tokens(tab_without_space, &tokens);
	return (tokens);
}
