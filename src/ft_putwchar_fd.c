/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 07:03:39 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/23 22:25:15 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/private_libft_includes.h"

/*
	Writes a unicode character "wc" to the "fd" file descriptor.
*/

static void	ft_putwchar_p2_fd(wint_t wc, char *str, int fd)
{
	if (wc <= 0x7F)
		str[0] = (unsigned char)wc;
	else if (wc <= 0x7FF)
	{
		str[0] = 0xC0 | (wc >> 6 & 0x1F);
		str[1] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0xFFFF)
	{
		str[0] = 0xE0 | (wc >> 12 & 0xF);
		str[1] = 0x80 | (wc >> 6 & 0x3F);
		str[2] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0x10FFFF)
	{
		str[0] = 0xF0 | (wc >> 18 & 0x7);
		str[1] = 0xE0 | (wc >> 12 & 0xF);
		str[2] = 0x80 | (wc >> 6 & 0x3F);
		str[3] = 0x80 | (wc & 0x3F);
	}
	ft_putstr_fd(str, fd);
}

int			ft_putwchar_fd(wint_t wc, int fd)
{
	int		rtn;
	char	*str;

	str = ft_strnew(4);
	rtn = 0;
	if (wc <= 127)
		rtn = 1;
	else if (wc >= 128 && wc <= 2047)
		rtn = 2;
	else if (wc >= 2048 && wc <= 65535)
		rtn = 3;
	else if (wc >= 65536 && wc <= 1114111)
		rtn = 4;
	ft_putwchar_p2_fd(wc, str, fd);
	free(str);
	return (rtn);
}
