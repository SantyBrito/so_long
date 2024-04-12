/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:40:54 by sbrito-a          #+#    #+#             */
/*   Updated: 2024/04/12 18:11:47 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	all_functions(va_list args, char i)
{
	int		length;
	char	a;

	length = 0;
	if (i == 'c')
	{
		a = va_arg(args, int);
		length += write(1, &a, 1);
	}
	else if (i == 's')
		length += funct_str(va_arg(args, char *));
	else if (i == 'p')
		length += funct_ptr(va_arg(args, unsigned long int));
	else if (i == 'd' || i == 'i')
		length += funct_dec(va_arg(args, int));
	else if (i == 'u')
		length += funct_unsigned_dec(va_arg(args, unsigned int));
	else if (i == 'x')
		length += funct_hex(va_arg(args, unsigned int), 0);
	else if (i == 'X')
		length += funct_hex(va_arg(args, unsigned int), 1);
	else if (i == '%')
		length += write(1, "%", 1);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += all_functions(args, str[i]);
		}
		else
		{
			length++;
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (length);
}
