/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:24:38 by dcandan           #+#    #+#             */
/*   Updated: 2022/10/31 12:28:32 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int a)
{
	if ((a < '0' || a > '9')
		&& (a < 'A' || a > 'Z') && (a < 'a' || a > 'z'))
	{
		return (0);
	}
	else
		return (1);
}