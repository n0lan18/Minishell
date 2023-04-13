/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:47:29 by synicole          #+#    #+#             */
/*   Updated: 2023/04/13 12:47:31 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"

/**
 * Change le comportement du signal SIGINT (ctrl-c)
 * Affiche un nouveau prompt sur une nouvelle ligne
 */
void	reset_prompt(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/**
 * Ignore le signal SIGQUIT (ctrl-\)
 */
static void	ignore_sigquit(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

/**
 * Change le comportement de certains signaux :
 * - SIGINT (ctrl-c)
 * - SIGQUIT (ctrl-\)
 */
void	set_signals(void)
{
	struct sigaction	sa;

	ignore_sigquit();
	sa.sa_handler = &reset_prompt;
	sigaction(SIGINT, &sa, NULL);
}
