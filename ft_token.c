/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:42:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/05 12:30:05 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_num_cmd_side(t_data *data, char *s)
{
	int	i;
	int side;

	i = 0;
	side = 1;
	while (s[i])
	{
		if (s[i] == '|' )
			side++;
		i++;
	}
	data->side = side;
}

int	ft_token_type(char *value)
{
	if (!ft_strcmp(value, "'"))
		return (S_QUOTE);
	else if (!ft_strcmp(value, "\""))
		return (D_QUOTE);
	else if (!ft_strcmp(value, "<"))
		return (RED_IN);
	else if (!ft_strcmp(value, ">"))
		return (RED_OUT);
	else if (!ft_strcmp(value, "<<"))
		return (RED_IN_APP);
	else if (!ft_strcmp(value, ">>"))
		return (RED_OUT_APP);
	else if (!ft_strcmp(value, "|"))
		return (PIPE);
	return (WORD);
}

// hdfh

t_files	*ft_new_node_files(int type, char *name)
{
	t_files *new;

	new = (t_files*)malloc(sizeof(t_files));
	if (!new)
		return (new);
	new->name = name;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	ft_add_back_file(t_files **file, int type, char *name)
{
	t_files	*new;
	t_files *last;

	last = *file;
	new = ft_new_node_files(type, name);
	if (new == NULL)
		return ;
	if (last == NULL)
	{
		*file = new;
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

void	list_files(t_token *token)
{
	t_files	*file;
	t_token *tmp;

	file = NULL;
	tmp = token;
	// printf("%s\n", tmp->value);
	while (tmp->next)
	{
		if (tmp->type >= 2 && tmp->type <= 4)
		{
			ft_add_back_file(&file, tmp->type, tmp->next->value);
		}
		tmp = tmp->next;
	}
	while (file)
	{
		printf("name of file is : %s -- type is : %d\n", file->name, file->type);
		file = file->next;
	}
}

// dffdjfs

t_token	*ft_new_node(char *value)
{
	t_token *new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (new);
	new->value = value;
	new->type = ft_token_type(value);
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_token **token, char *value)
{
	t_token *last;
	t_token	*new;

	last = *token;
	new = ft_new_node(ft_strtrim(value, " "));
	if (new == NULL)
		return ;
	if (last == NULL)
	{
		*token = new;
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

void	ft_token_side(t_data *data, char *s)
{
	int		j;
	int		start;
	int		quotes[2];
	t_token	*token;

	j = 0;
	start = 0;
	token = NULL;
	quotes[0] = 0;
	quotes[1] = 0;
	int node= 0;
	while (s[j])
	{
		if (s[j] == '\'' && quotes[1] % 2 == 0)
			quotes[0]++;
		else if (s[j] == '"' && quotes[0] % 2 == 0)
			quotes[1]++;
		if (quotes[1] % 2 || quotes[0] % 2)
		{
			j++;
			continue;
		}
		if (!ft_isspace(s[j]) && !is_special(s[j]))
		{
			while (s[j] && !ft_isspace(s[j]) && !is_special(s[j]))
				j++;
			ft_add_back(&token, ft_substr(s, start, j - start + !s[j  + 1]));
			start = j;
		}
		while (s[j] && ft_isspace(s[j]))
			j++;
		if (is_special(s[j]))
		{
			while (s[j] && is_special(s[j]))
				j++;
			ft_add_back(&token, ft_substr(s, start, j - start));
			start = j;
		}
		// if ((ft_isspace(s[j]) || !s[j + 1]) && (quotes[0] % 2 && quotes[1] % 2))
		// {
		// 	ft_add_back(&token, ft_substr(s, start, j - start + !s[j  + 1]));
		// 	start = j + 1;
		// }
		// j++;
	}
	t_token *tok;
	tok = token;
	while (token)
	{
		printf("type is %d\t\t value is %s\n", token->type, token->value);
		token = token->next;
	}
	list_files(tok);
}

void	ft_token(t_data *data, char *s)
{
	int     i;
	int		start;
	int		token = 0;
	int		side = 1;

	i = 0;
	start = i;
	ft_num_cmd_side(data, s);
	data->cmd_sides = ft_split(s, '|');
	// make_cmd_perfect(data, s);
	if (ft_check_syntax(data->cmd_line))
		return ;
	ft_token_side(data, data->cmd_line);
}
