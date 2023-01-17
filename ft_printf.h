/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:44:01 by btinturi          #+#    #+#             */
/*   Updated: 2022/11/02 16:07:50 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*** c part ***/
void		ft_putchar(char c);
int			ft_print_char(char c);

/*** xX part ***/
int			ft_hex_len(unsigned int num);
void		ft_put_hex(unsigned int num, const char forma);
int			ft_print_hex(unsigned int num, const char forma);

/*** s part ***/
int			ft_strlen(char *s);
void		ft_putstr(char *s);
int			ft_print_str(char *s);

/*** p part ***/
int			ft_ptr_len(uintptr_t num);
void		ft_put_ptr(uintptr_t num);
int			ft_print_ptr(unsigned long long ptr);

/*** d & i part ***/
char		*ft_itoa(int n);
int			ft_print_nbr(int n);

/*** % part ***/
int			ft_print_pourcent(void);

/*** u part ***/
int			ft_num_len(unsigned int num);
char		*ft_uitoa(unsigned int n);
int			ft_print_unsigned(unsigned int n);

/*** print part ***/
int			ft_forma(va_list args, const char forma);
int			ft_printf(const char *s, ...);
#endif
