/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:09:55 by synicole          #+#    #+#             */
/*   Updated: 2023/04/29 02:36:05 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "./libft/libft.h"

typedef enum part
{
	CMD,
	BUILTIN,
	PIPE,
	CHEVRON,
	QUOTE,
	DQUOTE,
	DKNOWN,
	SPACE,
}	t_part;

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_param
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				num;
	int				deb;
	char			**tab;
	char			*str;
}	t_param;

/*************Readline_to_tab***************/
int		search_in_str(char s, char *str);
int		count_word(const char *s, char c, int deb, int end);
int		count_word_fort_second_split(const char *s);
int		count_word_fort_second_split_bis(const char *s, int num, int i);
int		remove_space_begin_or_end(char *str, int pos);

/*************Readline_to_tab_bis**********/
char	**ft_split_next_gen(char const *s, char c, int deb, int end);
char	**ft_split_in_ft_split(char const *s);
char	**ft_split_in_ft_split_bis(char const *s, t_param a);
char	*ft_strcpy_new(char *dst, char *str, int deb, int end);
t_token	*split_new_format(char *rline, t_token *list);

/*************Check_dollar_in_list********/
t_token	*replace_dollar_if_first(t_token *list, t_token *env);
t_token	*replace_dollar_if_after(t_token *list, t_token *tmp, t_token *env);
t_token	*replace_dollar_if_after_bis(t_token *temp, t_token *tmp, t_token *env);
t_token	*replace_if_dollar(t_token *list, t_token *env);

/*************Check_dollar_in_list_bis****/
int		search_dollar_in_list(t_token *list);
int		compare_length_in_env(char *env);
char	*add_var_and_word(char *str, char *str1, char *tab);
char	*search_var_in_env(char *str, t_token *env);

/*************Rewrite_list*****************/
t_token	*rewrite(t_token *list, int num);
t_token	*hey_follow_tmp(t_token *list, char c, int num);
t_token	*rewrite_bis(t_token *tmp, t_token *new, char c, int num);
t_token	*rewrite_bis_bis(t_token *tmp, t_token *new);
t_token	*good_parse(t_token *list, t_token *env);

/*************Rewrite_list_bis*************/
t_token	*free_if_space_at_last(t_token *list);
int		just_space(char	*str);
t_token	*together_if_not_space_bis_bis(char *tmp, char *str, t_token *new);
t_token	*together_if_not_space_bis(t_token *tmp, char *str, t_token *new);
t_token	*together_if_not_space(t_token *list);

/*************check_words_in_tab***********/
int		check_which_type(char **tab, char **env);

/*************search_cmd*******************/
int		search_path_in_env(t_token *envp);
char	*join_all_path(char *env, char *cmd, char slash);
char	*existence_of_cmd(t_token *envp, char *cmd);
int		search_of_type_cmd(t_token *envp, char *tab);

/*************free_fonctions***************/
void	free_double_tab(char **tab);

/*************Fonctions_list***************/
void	add_element(t_token *list, char *tab);
t_token	*add_new_element(t_token *list, char *tab);
void	free_list(t_token *a);
int		search_case_in_list(t_token *list, char *str);
int		size_list(t_token *list);

/************* Signals ***********/
void	ft_init_signals(void);

/************* Closing functions ***********/
void	ft_close(void);

/************* External functions ***********/
void	rl_replace_line(const char *c, int i);

/*************which_type_of_case*************/
void	init_type_in_list(t_token *list, t_token *env);
int		search_which_type(char *str, t_token *list, t_token *env);

/*************check_if_built****************/
int		check_if_built(t_token *list, t_token *env);
int		check_if_built_bis(t_token *list);
int		check_if_built_bis_bis(t_token *list);
int		check_if_built_bis_bis_bis(t_token *tmp, t_token *env, int num);

/*************built_echo********************/
void	launch_echo(t_token *list, int check);
t_token	*launch_echo_bis(t_token *tmp, int j, int i);
int		search_str_in_str(char *first, char *second);

/*************built_env*********************/
t_token	*env_in_list(char **env, t_token *list);
void	launch_env(t_token *env);

/*************built_export******************/
void	launch_export(t_token *env, t_token *list);
char	*join_var(t_token *list);
void	check_if_var_exist(t_token *env, char *str);
int		check_if_var_is_good(char *str);
int		check_after_equal(char *str);

/*************built_unset******************/
void	launch_unset(t_token *env, t_token *list);

/*************built_pwd********************/
void	launch_pwd(t_token *env, t_token *list);

/*************built_cd********************/
void	launch_cd(t_token *env, t_token *list);

/*************check_if_command********************/
void	check_if_command(t_token *list, t_token *env);
char	**token_to_char(t_token *env);

#endif
