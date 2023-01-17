/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:17:37 by btinturi          #+#    #+#             */
/*   Updated: 2022/11/03 11:39:25 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char forma)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, forma);
		ft_put_hex(num % 16, forma);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
		{
			if (forma == 'x')
				ft_print_char(num - 10 + 'a');
			if (forma == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, const char forma)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, forma);
	return (ft_hex_len(num));
}
