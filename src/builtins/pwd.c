/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:22:51 by aabel             #+#    #+#             */
/*   Updated: 2023/08/29 14:50:38 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_space *space)
{
	char	*cwd;
	t_space	*current;

	current = space->crust;
	while (current)
	{
		space->chatab = ft_split(current->input, ' ');
		if (ft_strncmp(space->tab[0], "pwd", 4) == 0)
		{
			cwd = getcwd(NULL, 0);
			if (cwd == NULL)
			{
				perror("error directory");
				return ;
			}
			printf("%s\n", cwd);
			free(cwd);
		}
		free(space->chatab);
		space->chatab = NULL;
		current = current->crust->next;
	}
}
