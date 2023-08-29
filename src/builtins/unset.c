/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:43 by aabel             #+#    #+#             */
/*   Updated: 2023/08/29 16:30:49 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    unset(t_space *space)
{
    int		i;
    int		length;
    int		res;
	int		res_bis;
	t_core *current;

	current = space->crust;
	i = 1;
	while (current)
	{
		space->chatab = ft_split(current->str, ' ');
		length = ft_strlen(space->chatab[0]);
		if (ft_strncmp(space->chatab[0], "unset", 6) == 0 && length > 1)
		{
			lwhile (space->chatab[i])
			{
				res = ft_strncmp(space->chatab[i], "PATH", length);
				res_bis = ft_strncmp(space->chatab[i], "HOME", length);
				i++;
			}
		}
		current = current->next;
	} 
}