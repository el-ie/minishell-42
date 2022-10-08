/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:22:38 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 21:31:19 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/**
 * @brief defined in libftprintf.h
 * 
 */
typedef struct s_list		t_list;

typedef struct sigaction	t_sigaction;

/**
 * @brief Base Token
 * 
 */
typedef struct s_token
{
	char	*type;
	char	*value;
	int		id;
}				t_token;

typedef struct s_redirect
{
	int					type;
	void				*content;
}				t_redirect;

typedef struct s_redirect_fd
{
	int		type;
	int		fd;
	char	*op;
	char	*filename;
}				t_redirect_fd;

typedef struct s_heredoc
{
	int		id_operator;
	char	*limiter;
	char	*filename;
	int		expandable;
}				t_heredoc;

/**
 * @brief Struct base for the ast node
 */
typedef struct s_ast
{
	int			id;
	char		*type;
	char		*command;
	char		**args;
	t_redirect	**redirects;
	char		**env;
	char		*control;
	t_execution	*exec;
	void		*next;
}				t_ast;

/**
 * @brief This is the error struct for handleing error
 */
typedef struct s_error_state
{
	int	create_node;
	int	parse_simple_commad;
	int	to_string_type_error;
	int	malloc_error;
	int	*errors_addr_array[MAXIMUM_ERROR];
}				t_error_state;

typedef struct s_lexer_state
{
	int	inside_double_quote;
	int	inside_single_quote;
}				t_lexer_state;

typedef struct s_lexer_prompt
{
	int		s_quote_enabled;
	int		d_quote_enabled;
	int		type[3];
	char	*prompt;
	t_list	*list;
	int		i;
}				t_lexer_prompt;

typedef struct s_lexer_token
{
	unsigned int	id;
	int				type;
	size_t			length;
	char			*start_address;
	char			*end_address;
	int				free_able;
}				t_lexer_token;

typedef struct s_state_lex_env
{
	int	_name;
	int	_full;
	int	_split;
}				t_state_lex_env;

typedef struct s_env_var_token
{
	t_lexer_token	var_name;
	t_lexer_token	full_content;
	t_list			*splited_content;
}				t_env_var_token;

/**
 * @brief used insid prelexer_for_expand_prompt
 * 	type can be TOKEN_TYPE_LITERAL or TOKEN_TYPE_VARIABLE 
 */
typedef struct s_prelex_state
{
	char	*prompt;
	t_list	*sub_list;
	int		type[2];
	int		s_quote_enabled;
	int		i;
}				t_prelex_state;

typedef struct s_program_params
{
	int		argc;
	char	**argv;
	char	**envp;
	int		is_env_minimal_gen;
}				t_program_params;

typedef struct s_terminal_control
{
	struct termios	old;
	struct termios	new;
}				t_terminal_control;

/**
 * @brief Main struct for the program instance
 * 
 */
typedef struct s_data
{
	t_ast				*list_cmd;
	t_list				*lexer_tokens;
	int					is_lexer_okay;
	t_list				*here_doc_list;
	t_list				*env_dup_list;
	t_list				*expand_dup_list;
	int					count_line_for_heredoc_warn;
	int					status_last_cmd;
	t_error_state		errors;
	t_list				*list_env_token;
	t_list				*garbage_collector;
	t_program_params	main;
	char				*program_folder;
	char				current_folder[4096];
	char				*builtin_folder;
	char				*prompt_display;
	char				*string_type[TYPE_MAX];
	char				*string_ast_type[AST_TYPE_MAX];
	char				*temporary_histfile;
	struct sigaction	action_signal[MAX_ACT_SIG];
	t_terminal_control	tc;
	char				*builtin_list[8];
	int					(*builtin_functions[8])();
	int					is_tty_mode;
	int					error_on_terminal_cfg;
	int					exit_flag;
}				t_data;

#endif
