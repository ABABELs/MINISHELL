/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:08:32 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/30 18:33:16 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *size)
{
	if (write(1, &c, 1) == -1)
	{
		*size = -1;
		return ;
	}
	(*size)++;
}
