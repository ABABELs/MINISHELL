/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:11:45 by arthurabel        #+#    #+#             */
/*   Updated: 2023/08/22 11:48:19 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct t_data
{
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;
	pid_t	pid;
	int		fd[2];
}			t_data;

void	go_to_pipe(t_data *data);
int		get_nb_pipe(t_data *data);

#endif