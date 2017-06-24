/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:33:41 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 15:48:39 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*convert(long int num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convert_uns(unsigned int num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convert_uns_l(unsigned long long num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}
