/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:56:21 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/05 14:36:11 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	quick_parsing(int ac, char **av, t_data *data)
// {
// 	struct stat	sb;

// 	if (ac != 5)
// 		return (printf("run ./pipex file1 cmd1 cmd2 file2\n"), 1);
// 	// if (stat(av[1], &sb) == -1 || stat(av[4], &sb) == -1)
// 	// 	return (1);
// 	data = malloc(sizeof(t_data));
// 	data->infile = open(av[1], O_RDONLY);
// 	data->outfile = open(av[4], O_CREAT | O_RDWR);
// 	if (data->infile < 0 || data->outfile < 0)
// 		perror("failed to open in/outfile");
// 	data->cmd1 = av[2];
// 	data->cmd2 = av[3];
// }

int	get_nb_pipe(t_data *data)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = data;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	go_to_pipe(t_data *data)
{
	int		pipe_fd[2];
	pid_t	child_pid;
	int		i;
	int		prev_pipe_read;
	int		nb_node; // nb de noeud

	prev_pipe_read = 0;
	//nb_node = fonction pour calculer ne nombre de noeud
	i = -1;
	while (++i < nb_node)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return ;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			return ;
		}
		//child process
		if (child_pid == 0)
		{
			close(pipe_fd[0]);
			//connect input to previous read
			if (i > 0)
			{
				dup2(pipe_fd[1], STDIN_FILENO);
				close(prev_pipe_read);
			}
			//connect output to current write
			if (i < nb_node - 1)
			{
				dup2(pipe_fd[1], STDOUT_FILENO);
			}
			exec_all(data, i);
			exit(0);
		}
		//parent process
		else
		{
			close (pipe_fd[1]);
			if (i > 0)
				close(prev_pipe_read);
			prev_pipe_read = pipe_fd[0];
		}
	}
	close(prev_pipe_read);
	i = -1;
	while (++i < nb_node)
		wait(NULL);
}
