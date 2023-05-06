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

extern int	g_last_exit_code;

/** ----- ENUM ----- **/
enum e_token_type
{
	E_STRING,
	E_SPACE,
	E_BUILTIN,
	E_PIPE,
	E_REDIRECTION,
};

enum e_token_quote {
	E_NONE,
	E_SINGLE,
	E_DOUBLE
};

/** ----- STRUCTURES ----- **/
typedef struct s_env
{
	char			**envp;
	struct s_token	*token;
}	t_env;

typedef struct s_token
{
	int				type;
	char			*str;
	int				quote;
	struct s_token	*next;
}	t_token;

/** ----- ENV ----- **/
void	ft_init_env(t_env *env, char **envp);

/** ----- PARSING ----- **/
void	ft_parsing(t_env *env, char *readline);
void	ft_readline_to_token(t_env *env, char *readline);
int		ft_count_words(const char *s);
int		ft_skip_spaces(const char *s, int i);
int		ft_skip_quotes(const char *s, int i, char quote);
char	**ft_split_token(char const *s);
int		ft_contains_only_space(const char *s);
int		ft_is_space(char c);
int		ft_is_quotes(char c);
char	*ft_trim_str(const char *str);
int		ft_get_token_type(const char *str);
int		ft_get_token_quote(const char *str);
void	ft_dollar(t_env *env);
void	ft_trim_quote(t_env *env);
void	ft_join_token_not_separate_by_space(t_env *env);

/** ----- SIGNALS ----- **/
void	ft_init_signals(void);

/** ----- STRUCTS ----- **/
t_token	*ft_new_token(char *str);
void	ft_add_token_end(t_token **lst, t_token *token);

/** ----- BUILTIN ----- **/
void	ft_run_echo(t_token *list);
void	ft_run_cd(t_token *env, t_token *list);
void	ft_run_pwd(t_token *env, t_token *list);
void	ft_run_unset(t_token *env, t_token *list);
void	ft_run_env(t_token *env);
void	ft_run_export(t_token *env, t_token *list);

/** ----- EXIT ----- **/
void	ft_close(void);

/** ----- DEBUG ----- **/
void	db_print_tab(char **tab);
void	db_print_token(t_token *token);

/** ----- EXTERNAL ----- **/
void	rl_replace_line(const char *c, int i);

/*************Check_dollar_in_list********/
t_token	*replace_dollar_if_first(t_token *list, t_token *env);
t_token	*replace_dollar_if_after(t_token *list, t_token *tmp, t_token *env);
t_token	*replace_dollar_if_after_bis(t_token *temp, t_token *tmp, t_token *env);
t_token	*replace_if_dollar(t_token *list, t_token *env);
char	*ft_strcpy_new(char *dst, char *str, int deb, int end);

/*************Check_dollar_in_list_bis****/
int		search_dollar_in_list(t_token *list);
int		compare_length_in_env(const char *env);
char	*add_var_and_word(char *str, const char *str1, char *tab);
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

/*************Fonctions_list***************/
void	add_element(t_token *list, char *tab);
void	free_list(t_token *a);
int		search_case_in_list(t_token *list, char *str);
int		size_list(t_token *list);

/*************check_if_built****************/
int		check_if_built(t_token *list, t_token *env);
int		check_if_built_bis(t_token *list);
int		check_if_built_bis_bis(t_token *list);
int		check_if_built_bis_bis_bis(t_token *tmp, t_token *env);

/*************built_env*********************/
t_token	*env_in_list(char **env, t_token *list);

/*************check_if_command********************/
void	check_if_command(t_token *list, t_token *env);
char	**token_to_char(t_token *env);

#endif
