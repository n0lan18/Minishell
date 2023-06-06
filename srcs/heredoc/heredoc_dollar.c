/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:10:16 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 18:04:11 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Replace the dollar in the line by the correct value.
 *
 * @param env
 * @param line
 *
 * @return void
 */
void	ft_heredoc_dollar(t_env *env, char **line)
{
	t_dollar	*list_dollars;

	(void)env;
	list_dollars = NULL;
	ft_create_list_dollars(&list_dollars, *line);
	ft_replace_dollar_correct_value(env->envp, &list_dollars);
	db_print_dollar(list_dollars);
	free(*line);
	*line = ft_struct_dollar_to_char(list_dollars);
	ft_free_dollar(list_dollars);
}
