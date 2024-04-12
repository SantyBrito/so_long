/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:31:50 by sbrito-a          #+#    #+#             */
/*   Updated: 2024/04/12 18:12:12 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	funct_str(char *c)
{
	int	len;

	len = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[len])
	{
		len++;
	}
	return (write(1, c, len));
}

int	funct_ptr(unsigned long int n)
{
	int	digit;
	int	length;

	digit = 0;
	length = 0;
	if (n / 16)
		length += funct_ptr(n / 16);
	if (length == 0)
		length += write(1, "0x", 2);
	digit = n % 16;
	length += write(1, &"0123456789abcdef"[digit], 1);
	return (length);
}

int	funct_dec(int n)
{
	long	new;
	int		length;
	int		flag;

	new = (long)n;
	length = 0;
	flag = 0;
	if (new < 0)
	{
		length += write(1, "-", 1);
		new = -new;
	}
	if (new / 10)
		length += funct_dec(new / 10);
	new = new % 10 + '0';
	length += write(1, &new, 1);
	return (length);
}

int	funct_unsigned_dec(unsigned int n)
{
	long	new;
	int		length;

	new = (long)n;
	length = 0;
	if (new / 10)
		length += funct_dec(new / 10);
	new = new % 10 + '0';
	length += write(1, &new, 1);
	return (length);
}

int	funct_hex(unsigned int n, int flag)
{
	unsigned int	digit;
	int				length;

	digit = 0;
	length = 0;
	if (n >= 16)
		length += funct_hex(n / 16, flag);
	digit = n % 16;
	if (flag == 0)
		length += write(1, &"0123456789abcdef"[digit], 1);
	else
		length += write(1, &"0123456789ABCDEF"[digit], 1);
	return (length);
}
