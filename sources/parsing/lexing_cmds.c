/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:21:28 by ljerinec          #+#    #+#             */
/*   Updated: 2023/09/05 11:54:55 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	node_to_delete(t_list *lst)
{
	while (lst)
	{
		if (lst && ((t_content *)lst->content)->to_delete == 1)
		{
			lst = ft_lstdel_here(&lst, lst);
			if (lst)
				lst = lst->prev;
		}
		else if (lst)
			lst = lst->next;
	}
}

void	create_lst_cmds(t_data *big_data)
{
	// t_list		*lst_parsing_f;
	// t_list		*lst_cmds_f;

	// big_data->lst_cmds = create_data_lst();
	// lst_parsing_f = big_data->lst_parsing->first;
	// lst_cmds_f = big_data->lst_cmds->first;
	setup_lst_cmds(big_data, big_data->lst_parsing->first);
	node_to_delete(big_data->lst_parsing->first);
	check_redir_files(big_data);
	// node_to_delete(big_data->lst_parsing->first);
	print_lst_parsing(big_data->lst_parsing->first);
}

char	**array_join(char **array, char *line)
{
	int		i;
	char	**new_array;
	int		len;

	i = 0;
	if (!array)
		i = 0;
	else
		while (array[i])
			i++;
	len = i;
	new_array = malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = line;
	new_array[++i] = NULL;
	if (array)
		free(array);
	return (new_array);
}

void	ft_print_tab(char **array)
{
	int	i;

	i = -1;
	if (!array)
	{
		printf("array[0] = (NULL)\n");
		return ;
	}
	while (array[++i])
		printf("array[%d] = %s\n", i, array[i]);
}

void	setup_lst_cmds(t_data *big_data, t_list *lst)
{
	(void) big_data;
	t_content	*content;
	t_list		*save;

	save = NULL;
	while (lst)
	{
		if (lst)
			content = (t_content *)lst->content;
		while (lst && ((t_content *)lst->content)->type != PIPE)
		{
			content = (t_content *)lst->content;
			if (content->type == CMD)
			{
				if (save != NULL)
					content->to_delete = 1;
				else
					save = lst;
				((t_content *)save->content)->cmd = array_join(((t_content *)save->content)->cmd, content->word);
				if (lst == NULL)
					break ;
			}
			lst = lst->next;
		}
		if (lst)
			content = (t_content *)lst->content;
		if (lst && content->type == PIPE)
		{
			lst = lst->next;
			save = NULL;
		}
	}
}

t_cmds	*create_cmds(char *word, t_type type)
{
	t_cmds	*cmds;

	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (NULL);
	cmds->type = type;
	cmds->cmd = array_join(NULL, word);
	cmds->infile = -1;
	cmds->outfile = -1;
	return (cmds);
}

void	print_lst_cmds(t_data_lst *lst_cmds)
{
	t_list	*lst;
	t_cmds	*cmds_content;

	lst = lst_cmds->first;
	while (lst)
	{
		cmds_content = (t_cmds *)lst->content;
		if (cmds_content->type == CMD)
			ft_print_tab(cmds_content->cmd);
		else if (cmds_content->type == PIPE)
			ft_printf("|\n");
		lst = lst->next;
	}
}
