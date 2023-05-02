/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:54:47 by synicole          #+#    #+#             */
/*   Updated: 2023/05/02 14:54:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Prints the content of a char **tab.
 * @param char **tab
 *
 * @return void
*/
void	db_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("[%s]\n", tab[i++]);
}

/**
 * Prints the content of a token.
 * @param t_token *token
 *
 * @return void
*/
void	db_print_token(t_token *token)
{
	printf("(TOKEN)[%s] -> (TYPE)[%d]\n", token->str, token->type);
}
