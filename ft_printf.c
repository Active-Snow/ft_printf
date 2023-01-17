/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:22:05 by btinturi          #+#    #+#             */
/*   Updated: 2022/11/03 13:29:40 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_forma(va_list args, const char forma)
{
	int	pl;

	pl = 0;
	if (forma == 'c')
		pl += ft_print_char(va_arg(args, int));
	else if (forma == 's')
		pl += ft_print_str(va_arg(args, char *));
	else if (forma == 'p')
		pl += ft_print_ptr(va_arg(args, unsigned long long));
	else if (forma == 'd' || forma == 'i')
		pl += ft_print_nbr(va_arg(args, int));
	else if (forma == 'u')
		pl += ft_print_unsigned(va_arg(args, unsigned int));
	else if (forma == 'x' || forma == 'X')
		pl += ft_print_hex(va_arg(args, unsigned int), forma);
	else if (forma == '%')
		pl += ft_print_pourcent();
	else
		return (-1);
	return (pl);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		pl;

	i = 0;
	pl = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			pl += ft_forma(args, s[i + 1]);
			i++;
		}
		else
			pl += ft_print_char(s[i]);
		i++;
	}
	return (pl);
}
