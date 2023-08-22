/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:56:21 by arthurabel        #+#    #+#             */
/*   Updated: 2023/08/22 08:15:07 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quick_parsing(int ac, char **av, t_data *data)
{
	struct stat	sb;

	if (ac != 5)
		return (printf("run ./pipex file1 cmd1 cmd2 file2\n"), 1);
	// if (stat(av[1], &sb) == -1 || stat(av[4], &sb) == -1)
	// 	return (1);
	data = malloc(sizeof(t_data));
	data->infile = open(av[1], O_RDONLY);
	data->outfile = open(av[4], O_CREAT | O_RDWR);
	if (data->infile < 0 || data->outfile < 0)
		perror("failed to open in/outfile");
	data->cmd1 = av[2];
	data->cmd2 = av[3];
}