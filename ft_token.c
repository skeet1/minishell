/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:42:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/03 13:20:09 by mkarim           ###   ########.fr       */
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
	new = ft_new_node(value);
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
	quotes[0] = 1;
	quotes[1] = 1;
	while (s[j])
	{
		if (s[j] == '\'')
			quotes[0]++;
		else if (s[j] == '"')
			quotes[1]++;
		if ((ft_isspace(s[j]) || !s[j + 1] || s[j] == '|') && (quotes[0] % 2 && quotes[1] % 2))
		{
			ft_add_back(&token, ft_substr(s, start, j - start + !s[j  + 1]));
			if (s[j] == '|')
				ft_add_back(&token, "|");
			start = j + 1;
		}
		j++;
	}
	while (token)
	{
		printf("type is %d\t\t value is %s\n", token->type, token->value);
		token = token->next;
	}
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
	// ft_check_syntax(data);
	ft_token_side(data, s);
}