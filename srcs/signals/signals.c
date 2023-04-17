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
 * Cette fonction est appelée lorsqu'un signal est reçu.
 * Elle traite les signaux SIGINT et SIGQUIT de manière différente.
 * Affiche ou en réinitialise la ligne de commande selon le signal reçu.
 */
static void	ft_handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

/**
 * Initialise la gestion des signaux SIGINT et SIGQUIT.
 * Appelle la fonction ft_handle_signals() lorsqu'un signal est reçu.
 * Utilise la fonction sigaction() pour configurer la gestion des signaux.
 */
void	ft_init_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = ft_handle_signals;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		perror("Error: cannot handle SIGINT");
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		perror("Error: cannot handle SIGQUIT");
}
