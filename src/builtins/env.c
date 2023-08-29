/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:50 by aabel             #+#    #+#             */
/*   Updated: 2023/08/29 16:12:23 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	print_env(t_space *space)
{
    t_core *current;

    current = space->crust;
    while (current)
	{
		space->chatab = ft_split(current->str, ' ');
		if (ft_strncmp(space->chatab[0], "env", 4) == 0)
			print
	}
}