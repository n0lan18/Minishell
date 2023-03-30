/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:48:18 by nleggeri          #+#    #+#             */
/*   Updated: 2023/01/17 14:08:01 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthex(n / 16);
		i += ft_puthex(n % 16);
	}
	if (n < 16)
	{
		i++;
		if (n <= 9)
			percent_c(n + '0');
		else
			percent_c((n - 10) + 'a');
	}
	return (i);
}

int	percent_p(unsigned long long n)
{
	int	i;

	write(1, "0x", 2);
	i = ft_puthex(n);
	return (i + 2);
}
