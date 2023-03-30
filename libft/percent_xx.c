/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:17 by nleggeri          #+#    #+#             */
/*   Updated: 2023/01/17 14:07:47 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	percent_xx(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += percent_xx(n / 16, c);
		i += percent_xx(n % 16, c);
	}
	if (n < 16)
	{
		i++;
		if (n <= 9)
			percent_c(n + '0');
		else
		{
			if (c == 'x')
				percent_c((n - 10) + 'a');
			else if (c == 'X')
				percent_c((n - 10) + 'A');
		}
	}
	return (i);
}
