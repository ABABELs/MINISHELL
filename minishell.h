/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:11:45 by arthurabel        #+#    #+#             */
/*   Updated: 2023/08/22 08:13:02 by arthurabel       ###   ########.fr       */
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

typedef struct t_data
{
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;
	pid_t	pid;
	int		fd[2];
}			t_data;

// -> main.c
void	pipex(t_data *data);

// ->parsing.c
int		quick_parsing(int ac, char **av, t_data *data);

// -> process.c
void	ft_child(t_data *data);
void	ft_parent(t_data *data);

// -> ft_split.c
char	**ft_split(char *s, char c);
char	*create_word(char *s, char c);
int		count_words(char *s, char c);
int		is_separator(char c, char c1);

#endif