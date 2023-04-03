/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:09:55 by synicole          #+#    #+#             */
/*   Updated: 2023/04/03 00:44:26 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

typedef	struct	s_param
{
	int	i;
	int	j;
	int	x;
	int	y;
    int num;
    int deb;
}		t_param;

/*************Parsing***************/
void	readline_to_tab(char *readline);
int     count_words(char *readline, int i, int j, t_param inc);
char	**split_new_format(char **tab, char *str, int i, int j, t_param inc);
char	*ft_strcpy_new_format(char *dst, char *str, int deb, int end);
#endif
