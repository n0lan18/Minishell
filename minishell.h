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
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "./libft/libft.h"

typedef struct s_param
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		num;
	int		deb;
	char	**tab;
	char 	*str;
}	t_param;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

/************* Readline_to_tab ***************/
int			search_in_str(char s, char *str);
int			count_word(const char *s, char c, int deb, int end);
int			count_word_fort_second_split(const char *s);
int			count_word_fort_second_split_bis(const char *s, int num, int i);
char		**ft_split_next_gen(char const *s, char c, int deb, int end);
char		**ft_split_in_ft_split(char const *s);
char		**ft_split_in_ft_split_bis(char const *s, t_param a);
char		*ft_strcpy_new(char *dst, char *str, int deb, int end);
t_list		*split_new_format(char *rline, t_list *list);
int			remove_space_begin_or_end(char *str, int pos);

/************* Check_dollar_in_list ********/
t_list		*replace_dollar_if_first(t_list *list, char **env);
t_list		*replace_dollar_if_after(t_list *list, t_list *tmp, char **env);
t_list		*replace_dollar_if_after_bis(t_list *temp, t_list *tmp, char **env);
t_list		*replace_if_dollar(t_list *list, char **env);

/************* Check_dollar_in_list_bis ****/
int			search_dollar_in_list(t_list *list);
char		*add_var_and_word(char *str, char *str1, char *tab);
char		*search_var_in_env(char *str, char **env);
int			compare_length_in_env(char *env);

/************* check_words_in_tab ***********/
int			check_which_type(char **tab, char **env);

/************* search_cmd *******************/
int			search_path_in_env(char **envp);
char		*join_all_path(char *env, char *cmd, char slash);
char		*existence_of_cmd(char **env, char *cmd);
int			search_of_type_cmd(char **env, char *tab);

/************* free_fonctions ***************/
void		free_double_tab(char **tab);

/************* Fonctions_list ***************/
t_list		*add_new_element(t_list *list, char *tab);
t_list		*char_to_tab(char *tab, t_list *list);
void		free_list(t_list *a);
int			search_case_in_list(t_list *list, char *str);
int			size_list(t_list *list);

/************* Fonctions_list_bis ***********/
t_list		*remove_first_elem_if_var_NULL(t_list *list);
t_list		*remove_after_first_elem_list_if_NULL(t_list *list);

/************* Signals ***********/
void		ft_init_signals(void);

/************* Closing functions ***********/
void		ft_close(void);

/************* External functions ***********/
extern void	rl_replace_line(const char *c, int i);

#endif
