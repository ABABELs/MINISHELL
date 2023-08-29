/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:56:03 by aabel             #+#    #+#             */
/*   Updated: 2023/08/29 15:06:43 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_n(char **compare)
{
	int	i;
	int	j;

	i = 0;
	while (compare[++i])
	{
		j = 0;
		if (compare[i][j++] == '-' && compare[i][j] && compare[i][j] == 'n')
		{
			while (compare[i][j] == 'n')
				j++;
			if (compare[i][j] && compare[i][j] != 'n')
				return (1);
		}
		else
			return (i);
	}
	return (i);
}

void	echo(char **compare, t_space *space)
{
	int	i;
	int	k;

	k = 0;
	i = check_n(compare);
	while (compare[i])
	{
		echo_norme(i, k, compare);
		printf(" ");
		i++;
		k = 0;
	}
	printf("\n");
}
