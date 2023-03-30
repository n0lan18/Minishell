/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:32:20 by nleggeri          #+#    #+#             */
/*   Updated: 2023/01/17 14:06:22 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	if_percent(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += percent_c(va_arg (args, int));
	else if (c == 's')
		i += percent_s(va_arg (args, char *));
	else if (c == 'd' || c == 'i')
		i += percent_d(va_arg(args, int));
	else if (c == 'u')
		i += percent_u(va_arg(args, unsigned int), 0);
	else if (c == 'x' || c == 'X')
		i += percent_xx(va_arg(args, unsigned int), c);
	else if (c == 'p')
		i += percent_p(va_arg(args, unsigned long long));
	else
		i += percent_c('%');
	return (i);
}

int	ft_printf(const char *param, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, param);
	i = 0;
	count = 0;
	while (param[i])
	{
		if (param[i] == '%')
		{
			i++;
			count += if_percent(param[i], args);
			i++;
		}
		else
		{
			count += percent_c(param[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
