/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:56:03 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/06 11:35:38 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "minishell $ "
# define PRE_ERR "minishell: "
# define SNT_ERR "minishell: syntax error near unexpected token `"

typedef enum e_token {
	S_QUOTE,
	D_QUOTE,
	RED_IN,
	RED_OUT,
	RED_IN_APP,
	RED_OUT_APP,
	PIPE,
	FILEE,
	WORD
}		t_e_token;

/* ----------- START STRUCT FOR SPLIT ----------- */

typedef struct s_variables
{
	int		l;
	int		i;
	int		j;
	int		cl;
}			t_variables;

/* ----------- END STRUCT FOR SPLIT ----------- */

typedef struct s_data {
	char	*cmd_line;
	int		side;
	char	**cmd_sides;
}		t_data;

typedef	struct s_token {
	int		type;
	char	*value;
	int		dbl_qt;
	struct	s_token *next;
}				t_token;

typedef struct	s_files {
	int	type;
	char *name;
	struct s_files *next;
}			t_files;

size_t	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

typedef struct s_cmdl {
	char	*cmd;
	char	**args;
	char	*in_red;
	char	*out_red;
}		t_cmdl;

int		ft_is_alpha(char c);
char    *rm_spaces(char *s);
int		check_valid(char *s);
size_t		ft_strlen(char *s);
int	    check_err_pipe(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strtrim(char *s1, char *set);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int	ft_isspace(int c);
t_token	*ft_token(t_token *token, t_data *data, char *s);
char	**ft_split(char *s, char c);
int	ft_strcmp(char *s1, char *s2);
int    ft_check_syntax(char *s);
// void    make_cmd_perfect(t_data *data, char *s);
int	ft_isalnum(int c);
char	*ft_strcat(char *dest, char *src);
int	is_special(char c);
void	remove_quotes(t_token *token);
void	incr_quotes(char c, int *a, int *b);
void	print_token(t_token *token);

#endif
