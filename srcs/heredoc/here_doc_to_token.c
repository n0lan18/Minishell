/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_to_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:13:50 by nleggeri          #+#    #+#             */
/*   Updated: 2023/05/30 18:04:03 by nleggeri         ###   ########.fr       */
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
static t_token	*ft_array_to_token(char **tab, t_token *token)
{
	int	i;

	token = ft_new_token(tab[0]);
	i = 1;
	while (tab[i])
	{
		ft_add_token_end(&token, ft_new_token(tab[i]));
		i++;
	}
	return (token);
}

/**
 * Converts a string input to an array of tokens
 * @param char *line to be converted to tokens
 * @param t_token *token
 *
 * @return void
*/
t_token	*ft_heredoc_to_token(t_token *token, char *line)
{
	char	**split_space_tab;

	split_space_tab = ft_split_token(ft_trim_str(line));
	token = ft_array_to_token(split_space_tab, token);
	return (token);
}
