/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:55:29 by arthurabel        #+#    #+#             */
/*   Updated: 2023/08/22 08:20:33 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	pipex(t_data *data)
{
	if (pipe(data->fd) == -1)
		return ((void)printf("Pipe Failed\n"));
	data->pid = fork();
	if (data->pid < 0)
		return ((void)printf("Fork Failed\n"));
	if (data->pid == 0)
		ft_child(data);
	else
		ft_parent(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5)
		return (0);
	if (quick_parsing(argc, argv, &data) == -1)
		return (printf("Error\n"), 1);
	pipex(&data);
	return (0);
}