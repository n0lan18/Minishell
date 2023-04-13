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

// Routine de gestion de SIGINT
void	reset_prompt(int signal)
{
	(void) signal;
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ignore_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGINT, &act, NULL);
}

/**
 * Déclaration de la structure sigaction
 * Met à 0 tous les bits dans la structure,
 * sinon on aura de mauvaises surprises de valeurs non-initialisées...
 *
 * On voudrait invoquer la routine sigint_handler quand on reçoit le signal :
 * Applique cette structure avec la fonction à invoquer au signal SIGINT (ctrl-c)
 */
void	set_signal_action(void)
{
	struct sigaction	sa;

	ignore_sigquit();
	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = &reset_prompt;
	sigaction(SIGINT, &sa, NULL);
}
