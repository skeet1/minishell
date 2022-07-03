/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:42:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/03 09:24:29 by mkarim           ###   ########.fr       */
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
		return (D_RED_IN);
	else if (!ft_strcmp(value, ">>"))
		return (D_RED_OUT);
	else if (!ft_strcmp(value, "|"))
		return (PIPE);
	return (WORD);
}

t_token	*ft_new_node(char *value)
{
	t_token *new;

	new = (t_token *)malloc(sizeof(t_token));
	new->value = value;
	new->type = ft_token_type(value);
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_token **tok, char *value)
{
	t_token	*new;
	t_token *token;

	token = *tok;
	new = ft_new_node(value);
	printf("type is %d\t, value is : %s\n", new->type, new->value);
	if (!token)
		token = new;
	else
	{
		while (token->next)
		{
			token = token->next;
		}
		token->next = new;
	}
}

void	ft_token_side(t_data *data, char *s)
{
	int		i;
	int		j;
	int		start;
	t_token	*token;

	i = 0;
	j = 0;
	start = 0;
	token = NULL;
	while (s[j])
	{
		if (ft_isspace(s[j]) || !s[j + 1])
		{
			ft_add_back(&token, ft_substr(s, start, j - start + !s[j  + 1]));
			start = j + 1;
		}
		j++;
	}
	// printf("hi\n");
	while (token)
	{
		printf("hi2578\n");
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
	ft_token_side(data, s);
	// printf("sides : %d\n", data->side);
}