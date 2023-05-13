/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:09:55 by synicole          #+#    #+#             */
/*   Updated: 2023/05/10 19:04:49 by nleggeri         ###   ########.fr       */
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

/** ----- GLOBAL VARIABLE ----- **/
extern int				g_last_exit_code;

/** ----- STRUCTURES ----- **/
typedef struct s_env	t_env;
typedef struct s_envp	t_envp;
typedef struct s_token	t_token;
typedef struct s_dollar	t_dollar;

typedef struct s_env
{
	t_envp	*envp;
	t_token	*token;
}	t_env;

typedef struct s_envp
{
	char	*line;
	char	*name;
	char	*value;
	t_envp	*next;
}	t_envp;

typedef struct s_token
{
	int		type;
	char	*str;
	int		quote;
	t_token	*next;
}	t_token;

typedef struct s_dollar
{
	char		*str;
	t_dollar	*next;
}	t_dollar;

/** ----- ENUM ----- **/
enum e_token_type
{
	E_STRING,
	E_SPACE,
	E_BUILTIN,
	E_PIPE,
	E_REDIRECTION,
	E_FILE,
	E_CMD
};

enum e_token_quote {
	E_NONE_QUOTE,
	E_SINGLE_QUOTE,
	E_DOUBLE_QUOTE
};

/** ----- ENV ----- **/
void		ft_init_env(t_env *env, char **envp);

/** ----- ENVP ----- **/
void		ft_init_envp(t_env *env, char **envpchar);
char		**ft_envp_to_char(t_envp *envp);
char		*ft_get_envp_value(const char *str);
char		*ft_get_envp_name(const char *str);
int			ft_valid_identifier_todo(int c);

/** ----- PARSING ----- **/
void		ft_parsing(t_env *env, char *readline);
void		ft_readline_to_token(t_env *env, char *readline);
int			ft_count_words(const char *s);
int			ft_skip_spaces(const char *s, int i);
int			ft_skip_quotes(const char *s, int i, char quote);
char		**ft_split_token(char const *s);
int			ft_contains_only_space(const char *s);
int			ft_is_space(char c);
int			ft_is_quotes(char c);
char		*ft_trim_str(const char *str);
int			ft_get_token_type(const char *str);
int			ft_get_token_quote(const char *str);
void		ft_dollar(t_env *env);
int			ft_contains_dollar(const char *str);
void		ft_create_list_dollars(t_dollar **list, const char *str, int i);
void		ft_trim_quote(t_env *env);
void		ft_join_token_not_separate_by_space(t_env *env);
void		ft_type(t_env *env);

/** ----- EXECUTION ----- **/
void		ft_execute(t_env *env);
int			ft_is_builtins(char *str);
void		ft_execute_builtins(t_env *env);

/** ----- SIGNALS ----- **/
void		ft_init_signals(void);

/** ----- STRUCTS ----- **/
t_token		*ft_new_token(char *str);
void		ft_add_token_end(t_token **lst, t_token *token);
t_envp		*ft_new_envp(char *str);
void		ft_add_envp_end(t_envp **lst, t_envp *envp);
void		ft_remove_envp(t_envp **lst, char *str);
int			ft_size_list_envp(t_envp *list);
t_dollar	*ft_new_dollar(char *str);
void		ft_add_dollar_end(t_dollar **lst, t_dollar *new);

/** ----- BUILTIN ----- **/
void		ft_exec_echo(t_token *list);
void		ft_exec_env(t_envp *envp);
void		ft_exec_unset(t_env *env);
void		ft_exec_export(t_env *env);
void		ft_exec_pwd(void);
void		ft_exec_cd(t_token *list);
void		ft_exec_exit(void);

/** ----- EXIT ----- **/
void		ft_exit(int status, char *message);

/** ----- DEBUG ----- **/
void		db_print_tab(char **tab);
void		db_print_token(t_token *token);
void		db_print_envp(t_envp *envp);
void		db_print_dollar(t_dollar *dollar);

/** ----- EXTERNAL ----- **/
void		rl_replace_line(const char *c, int i);

/** ----- UTILS ----- **/
void		free_double_tab(char **tab);

/*************check_if_built****************/
int			check_if_built(t_token *list, t_token *env);
int			check_if_built_bis(t_token *list);
int			check_if_built_bis_bis(t_token *list);
int			check_if_built_bis_bis_bis(t_token *tmp, t_token *env);

/*************built_env*********************/
t_token		*env_in_list(char **env, t_token *list);

/*************check_if_command********************/
void		check_if_command(t_token *list, t_token *env);
char		**token_to_char(t_token *env);

int     search_of_type_cmd(t_envp *env, char *tab);
#endif
