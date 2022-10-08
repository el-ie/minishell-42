/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:55:15 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 00:34:19 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

/**
 * @brief WHEN EXITED A CHILD PROCESS WILL MULTIPLY WITH THISS VALUE 
 * 
 */
typedef enum e_const
{
	RESET_GET_FD_OPEN = -1,
	GET_FD_OPEN,
	CHILD_COEF = 256,
}			t_const;

typedef enum e_bool
{
	FALSE,
	TRUE,	
}			t_bool;

typedef enum e_action_signal
{
	ACT_MINISHELL,
	ACT_HEREDOC,
	ACT_PIPE,
	ACT_IGNORE,
	ACT_DEFAULT,
	MAX_ACT_SIG,
}			t_action_signal;

typedef enum e_status_returned
{
	STATUS_SIGQUIT = 0,
	STATUS_SIGINT = 130,
}		t_status_returned;

typedef enum e_ast_type
{
	AST_TYPE_COMMAND,
	AST_TYPE_PIPE,
	AST_TYPE_MAX
}			t_ast_type;
typedef enum e_reserved_word_array
{
	R_IF,
	R_THEN,
	R_ELSE,
	R_ELIF,
	R_FI,
	R_DO,
	R_DONE,
	R_CASE,
	R_ESAC,
	R_WHILE,
	R_UNTIL,
	R_FOR,
	R_LBRACE,
	R_RBRACE,
	R_BANG,
	R_IN,
	R_MAX,
}				t_reserved_word_array;

typedef enum e_to_string_type
{
	TYPE_OPERATOR_UNDEFINED,
	TYPE_OPERATOR_PIPE,
	TYPE_OPERATOR_D_GREAT,
	TYPE_OPERATOR_D_LESS,
	TYPE_OPERATOR_GREAT,
	TYPE_OPERATOR_LESS,
	TYPE_TOKEN_UNDEFINED,
	TYPE_TOKEN_LITERAL,
	TYPE_TOKEN_OPERATOR,
	TYPE_TOKEN_BLANK,
	TYPE_TOKEN_LIMITER,
	TYPE_TOKEN_FILENAME,
	TYPE_TOKEN_COMMAND,
	TYPE_TOKEN_ARGUMENT,
	TYPE_MAX,
}			t_to_string_type;

typedef enum e_spec_op_value
{
	OPERATOR_UNDEFINED,
	OPERATOR_PIPE,
	OPERATOR_D_GREAT,
	OPERATOR_D_LESS,
	OPERATOR_GREAT,
	OPERATOR_LESS,
	OPERATOR_MAX_VALUE,
	OPERATOR_APPEND,
}			t_spec_op_value;

/**
 * @brief Adjustement for start at 42 
 * 			is for avoid conflict with
 * 			OPERATOR_* enum
 * 
 */
typedef enum e_token_type
{
	TOKEN_TYPE_UNDEFINED = 42,
	TOKEN_TYPE_LITERAL,
	TOKEN_TYPE_VARIABLE,
	TOKEN_TYPE_OPERATOR,
	TOKEN_TYPE_BLANK,
	TOKEN_TYPE_LIMITER,
	TOKEN_TYPE_FILENAME,
	TOKEN_TYPE_COMMAND,
	TOKEN_TYPE_ARGUMENT,
	TOKEN_TYPE_MAX,
}			t_token_type;

typedef enum e_node_type
{
	NODE_TYPE_COMMAND,
	NODE_TYPE_TOKEN,
	NODE_TYPE_T_REDIRECT,
	NODE_TYPE_REDIRECT_FD,
	NODE_TYPE_LEXER_TOKEN,
	NODE_TYPE_ENV_VAR_TOKEN,
	NODE_TYPE_HEREDOC,
	MAXIMUM_NODE_TYPE,
}			t_node_type;

typedef enum e_error
{
	CREATE_NODE_ERROR,
	PARSE_SIMPLE_COMMAND_ERROR,
	TYPE_TO_STRING_ERROR,
	MALLOC_ERROR,
	MAXIMUM_ERROR,
}			t_error;

typedef enum e_node_connect_type
{
	CONNECT_AST_TYPE,
	CONNECT_REDIRECT_TYPE,
	CONNECT_NEXT_TYPE,
}			t_node_connect_type;

/**
 * @brief For the return value of is error
 * 
 */
typedef enum e_error_state_bool
{
	NO_ERROR,
	ERROR,
}			t_error_state_bool;

typedef enum e_lexer_access_token_properties
{
	OBJ,
	TYPE,
	LENGHT,
	START,
	END,
	MAX_PROPS,
}			t_lexer_access_token_properties;

typedef enum e_env_access_object
{
	NAME,
	FULL_CONTENT,
	SPLIT_CONTENT,
	MAX_ACCESS_CHILD,
}			t_env_access_object;

typedef enum e_lexer_type
{
	LEX_UNDEFINED,
	LEX_SINGLE_QUOTE,
	LEX_DOUBLE_QUOTE,
	LEX_WORD,
	LEX_OPERATOR,
	LEX_FULL_STRING,
	LEX_SPACE,
	LEX_OP_AND,
	LEX_OP_OR,
	LEX_OP_LESS,
	LEX_OP_GREAT,
	LEX_OP_PIPE,
	LEX_OP_DOLLAR,
	LEX_ALNUM,
	LEX_ENV_EQUAL,
	LEX_ENV_SPLIT,
	LEX_ENV_VAR_NAME,
	LEX_ENV_FULL_VALUE,
	LEX_MAX_TOKEN,
}			t_lexer_type;

typedef enum e_lexer_type_token
{
	TYPE_LEXER_WORD,
	TYPE_LEXER_EXPAND,
	TYPE_LEXER_OPERATOR
}			t_lexer_type_token;

#endif
