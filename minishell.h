/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:09:55 by synicole          #+#    #+#             */
/*   Updated: 2023/05/30 17:47:53 by nleggeri         ###   ########.fr       */
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

/** ----- DEFINE ----- **/
# define DEBUG_TOKEN 0
# define DEBUG_CMD 0
# define PATH_MAX 1024

/** ----- STRUCTURES ----- **/
typedef struct s_env	t_env;
typedef struct s_envp	t_envp;
typedef struct s_token	t_token;
typedef struct s_dollar	t_dollar;
typedef struct s_cmd	t_cmd;

typedef struct s_env
{
	t_envp	*envp;
	t_token	*token;
	t_cmd	*cmd;
	int		syntax_error_type;
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
	int		redirection;
	int		show;
	t_token	*next;
	t_token	*previous;
}	t_token;

typedef struct s_dollar
{
	char		*str;
	t_dollar	*next;
}	t_dollar;

typedef struct s_cmd {
	char	*name;
	char	**option;
	int		fd_read;
	int		fd_write;
	t_cmd	*next;
}	t_cmd;

/** ----- ENUM ----- **/
enum e_token_type
{
	E_STRING,
	E_SPACE,
	E_PIPE,
	E_REDIRECTION,
};

enum e_token_quote {
	E_NONE_QUOTE,
	E_SINGLE_QUOTE,
	E_DOUBLE_QUOTE
};

enum e_redirection {
	E_NOREDIRECTION,
	E_INFILE,
	E_OUTFILE,
	E_HEREDOC,
	E_APPEND
};

enum e_syntax_error_type {
	E_SYNTAX_QUOTE_CLOSE = 1,
	E_SYNTAX_REDIRECTION = 2,
	E_SYNTAX_PIPE = 3,
	E_SYNTAX_HEREDOC = 4,
};

/** ----- ENV ----- **/
void		ft_init_env(t_env *env, char **envp);

/** ----- ENVP ----- **/
void		ft_init_envp(t_env *env, char **envpchar);
char		**ft_envp_to_char(t_envp *envp);
char		*ft_get_envp_value(const char *str);
char		*ft_get_envp_name(const char *str);
int			ft_valid_identifier(int c);
char		*ft_get_envp_value_by_name(t_envp *envp, char *name);
char		**ft_get_splited_path(t_envp *envp);

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
int			ft_is_redirection(const char *str);
char		*ft_trim_str(const char *str);
void		ft_dollar(t_env *env);
int			ft_contains_dollar(const char *str);
void		ft_create_list_dollars(t_dollar **list, const char *str, int i);
void		ft_trim_quote(t_env *env);
void		ft_join_token_not_separate_by_space(t_env *env);
void		ft_command(t_env *env);

/** ----- HEREDOC ----- **/
void		ft_heredoc(t_env *env);
char		*ft_heredoc_getname(int version);
int			ft_heredoc_is_eof(t_token *eof, char *line);
char		*ft_heredoc_strjoin(char *s1, char *s2);
void		ft_heredoc_error(t_env *env);
int			ft_heredoc_is_valid_eof(t_env *env, t_token *token);
char		*ft_replace_dollar_in_line(t_env *env, char *line);
t_token		*ft_heredoc_to_token(t_token *token, char *line);
void		ft_heredoc_remove(t_env *env);

/** ----- SYNTAX ----- **/
int			ft_has_syntax_error(t_env *env);
int			ft_quote_is_valid(char *str);
int			ft_redirection_is_valid(t_token *token);
int			ft_pipe_is_valid(t_token *token);

/** ----- REDIRECTION ----- **/
void		ft_open_files_redirection(t_token **token, t_cmd *cmd);

/** ----- BUILTIN ----- **/
int			ft_is_builtins(const char *str);
int			ft_execute_builtins(t_env *env, t_cmd *cmd);
int			ft_exec_echo(char **option);
int			ft_exec_env(t_envp *envp);
int			ft_exec_unset(t_env *env, char **option);
int			ft_exec_export(t_env *env, char **option);
int			ft_exec_pwd(void);
int			ft_exec_cd(t_env *env, char **option);
void		ft_exec_exit(void);

/** ----- EXECUTION ----- **/
void		ft_execute(t_env *env);
void		ft_execute_external_in_fork(t_env *env);
void		ft_run_cmd(t_env *env, t_cmd *cmd);
void		ft_execute_external(t_env *env, t_cmd *cmd);
void		ft_prepare_fds(t_cmd *cmd, const int *fd_pipe_tmp, int *fd_pipe);
void		ft_close_fds(t_cmd *cmd, int *fd_pipe_read_tmp, int *fd_pipe);
void		ft_handle_exit_status(int exit_status);

/** ----- SIGNALS ----- **/
void		ft_init_signals(void);

/** ----- STRUCTS ----- **/
t_token		*ft_new_token(char *str);
void		ft_add_token_end(t_token **lst, t_token *token);
void		ft_add_token_previous(t_token *token);
t_envp		*ft_new_envp(char *str);
void		ft_add_envp_end(t_envp **lst, t_envp *envp);
void		ft_remove_envp(t_envp **lst, char *str);
int			ft_size_list_envp(t_envp *list);
t_dollar	*ft_new_dollar(char *str);
void		ft_add_dollar_end(t_dollar **lst, t_dollar *new);
void		ft_add_cmd_end(t_cmd **lst, t_cmd *new);

/** ----- PRINT ----- **/
void		ft_print_cmd_not_found(char *cmd_name);
void		ft_print_not_a_valid_identifier(char *str, char *builtin_name);

/** ----- FREE ----- **/
void		ft_free_token(t_env *env);
void		ft_free_liste_token(t_token *token);
void		ft_free_cmd(t_env *env);
void		ft_free_envp(t_env *env);
void		ft_free_tab(char **tab);

/** ----- EXIT ----- **/
void		ft_exit(int status, char *message);
int			ft_close(t_env *env);

/** ----- DEBUG ----- **/
void		db_print_tab(char **tab);
void		db_print_token(t_token *token);
void		db_print_cmd(t_cmd *cmd);
void		db_print_envp(t_envp *envp);
void		db_print_dollar(t_dollar *dollar);

/** ----- EXTERNAL ----- **/
extern void	rl_replace_line(const char *c, int i);

#endif
