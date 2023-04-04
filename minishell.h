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

/*************Readline_to_tab***************/
char	**readline_to_tab(char *readline);
int     count_words(char *readline, int i, int j, t_param inc);
char	**split_new_format(char **tab, char *str, int i, int j, t_param inc);
char	*ft_strcpy_new_format(char *dst, char *str, int deb, int end);

/*************Replace_dollar_in_tab********/
int search_quote_in_tab(char **tab);
char *ft_strcpy(char *dst, char *src, int deb, int end);
char    **check_if_dollar(char **tab, char **env, t_param inc);
char *ft_strcpy(char *dst, char *src, int deb, int end);
char *search_var_in_env(char *str, char **env);
char *add_var_and_word(char *str, char *str1, char *tab);

/*************check_words_in_tab***********/
int    check_which_type (char **tab, char **env);

/*************search_cmd*******************/
int	    search_path_in_env(char **envp);
char	*join_all_path(char *env, char *cmd, char slash);
char	*existence_of_cmd(char **env, char *cmd);
int     search_of_type_cmd(char **env, char *tab);

/*************free_fonctions***************/
void    free_double_tab(char **tab);

#endif
