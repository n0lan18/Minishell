/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:15:22 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 22:15:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Parses t_dollar list and replaces the dollar variables with their values.
 *
 * @param envp
 * @param **list
 *
 * @return void
 */
//static void	ft_replace_dollar_correct_value(t_envp *envp, t_dollar **list)
//{
//	t_dollar	*current;
//	char		*tmp;
//	char		*trimmed;
//
//	current = *list;
//	while (current)
//	{
//		if (current->str[0] == '$' && current->str[1] == '?')
//		{
//			tmp = current->str;
//			current->str = ft_itoa(g_last_exit_code);
//			free(tmp);
//		}
//		else if (current->str[0] == '$' && current->str[1])
//		{
//			tmp = current->str;
//			trimmed = ft_strtrim(current->str, "$");
//			current->str = ft_get_envp_value_by_name(envp, trimmed);
//			free(tmp);
//			free(trimmed);
//		}
//		current = current->next;
//	}
//}

static int	ft_len_tab(char **tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

static char	*ft_tab_to_str(char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = malloc(sizeof(char) * (ft_len_tab(tab) + 1));
	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			str[k] = tab[i][j];
			k++;
			j++;
		}
		i++;
	}
	str[k] = 0;
	return (str);
}

static int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/**
 * Replaces the dollar variables in the given token.
 * 1. Trim the token from the double quotes.
 * 2. Create a list of t_dollar from the given token.
 * 3. Replace the values of the t_dollar list.
 * 4. Replace the token with the new string.
 *
 * @param env
 * @param current
 *
 * @return void
 */
static void	ft_replace_dollar(t_env *env, t_token *current)
{
	// Get the first splitted array
	char	*trimmed;
	char	**splitted;
	trimmed = ft_strtrim(current->str, "\"");
//	printf("current->str: [%s]\n", trimmed);
	splitted = ft_dollar_split(trimmed);
	free(trimmed);
	db_print_tab(splitted);

	// Replace the values of the splitted array to a new array
	int		i;
	char	**splitted2;
	i = 0;
	splitted2 = malloc(sizeof(char *) * (ft_size_tab(splitted) + 1));
	while (i < ft_size_tab(splitted))
	{
		if (ft_contains_only_space(splitted[i]))
			splitted2[i] = ft_strdup(splitted[i]);
		else if (splitted[i][0] == '?')
			splitted2[i] = ft_itoa(g_last_exit_code);
		else
			splitted2[i] = ft_get_envp_value_by_name(env->envp, splitted[i]);
		i++;
	}
	splitted2[i] = NULL;
	ft_free_tab(splitted);

	free(current->str);
	current->str = ft_tab_to_str(splitted2);
//	printf("new_str: [%s]\n", current->str);
	db_print_tab(splitted2);
	ft_free_tab(splitted2);
}

/**
 * Parses the tokens and replaces the dollar variables if needed.
 *
 * @param *env
 *
 * @return void
 */
void	ft_dollar(t_env *env)
{
	t_token	*current;

	current = env->token;
	while (current)
	{
		if (current->type == E_STRING && current->quote != E_SINGLE_QUOTE
			&& ft_contains_dollar(current->str))
			ft_replace_dollar(env, current);
		current = current->next;
	}
}
