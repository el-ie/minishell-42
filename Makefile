CC= gcc
CFLAGS = -g3 -Wall -Wextra -Werror# -Wpadded
LFLAGS =  -lreadline ./libftprintf/libftprintf.a ./libcolor/libcolor.a
NAME = minishell
DEBUG_LEAK = valgrind_leak_suppress_realine_error
DEP = 	./minishell.h \
		./include/ast.h \
		./include/ctypes.h \
		./include/enum.h \
		./include/error.h \
		./include/execution.h \
		./include/fake_function.h \
		./include/garbage_collector.h \
		./include/get_next_line.h \
		./include/history_manager.h \
		./include/init.h \
		./include/lexer.h \
		./include/parser_part_two.h \
		./include/parser.h \
		./include/prompt_handler.h \
		./include/signal_handler.h \
		./include/structure.h \
		./include/subject_boundary.h \
		./include/terminal_control.h \
		./include/terminal_mode.h \
		./include/utils.h 

# creation of prefixs
F_UTILS =					./utils/
F_UTILS__GETTERS =			./utils/getters/
F_UTILS__SETTERS =			./utils/setters/
F_ENV_PARSE =				./env_parse/
F_ENV_HANDLER =				./env_handler/
F_CTYPE =					./ctype/
F_SUBJECT_BOUNDARY =		./subject_boundary/
F_SIGNAL_HANDLER =			./signal_handler/
F_PARSER		=			./parser/
F_TERMINAL_CONTROL =		./terminal_control/
F_TERMINAL_MODE =			./terminal_mode/
F_GARBAGE_COLLECTOR =		./garbage_collector/
F_RANDOM_GENERATOR =		./random_name_generator/
F_LEXER =					./lexer/
F_LEXER__HEREDOC =			./lexer/heredoc/
F_LEXER__UTILS =			./lexer/utils/
F_AST__NODE_HANDLER =		./ast/node_handler/
F_AST__ARGUMENT_EXTRACT =	./ast/argument_extract/
F_AST__PARSER_UTILS =		./ast/parser_utils/
F_ERROR_HANDLER =			./error_handler/
F_HISTORY_MANAGER =			./history_manager/
F_GNL =						./get_next_line/
F_PROMPT_HANDLER =			./prompt_handler/
F_INIT =					./init/
F_MINISHELL =				./
F_EXECUTION =				./pipex_adaptation/srcs/
F_EXECUTION__BUILTIN =		./pipex_adaptation/builtin/


SRC_UTILS =					dup_token_to_str.c \
							put_tokenstr_endl.c \
							put_lexer_token_fd.c \
							tokennstrcmp.c \
							is_envp_empty.c \
							clean_exit.c \
							free_prompt.c \
							check_malloc_fails_safe_exit.c \
							free_string_array.c \
							iterate_until_next_same_char_as_first.c \
							interactive_behavior.c \
							set_and_print_err_syntax.c

SRC_UTILS__GETTERS =		get_data.c \
							get_env_addr.c

SRC_UTILS__SETTERS =		set_program_folders.c \
							set_program_params.c

SRC_ENV_PARSE =				parse_env.c \
							get_token_length.c \
							check_if_char_is_in_str.c \
							count_until_char_found.c \
							sub_tokenisation.c \
							check_end_of_value.c \
							create_minimal_env.c

SRC_ENV_HANDLER =			get_env_t_list.c \
							is_var_exist_in_env.c \
							get_env_value.c \
							do_cmp_env.c \
							is_cmp_perfect_match.c \
							get_env_t_list_addr.c \
							is_env_token_malloced.c \
							set_env_by_var_name.c \
							print_all_env_t_list.c \
							export_env_to_array.c \
							set_up_content.c \
							subtoken_update.c \
							remove_env_var_if_exist.c \
							init_vars.c \
							new_env_var_lex_token.c \


SRC_CTYPE =					is_char_backslash.c \
							is_char_double_quote.c \
							is_char_single_quote.c \
							is_char_semicolon.c \
							is_char_dollar.c \
							ft_is_underscore.c \
							ft_isnum.c \
							ft_isalpha.c \
							ft_isuppercase.c \
							ft_islowercase.c \
							ft_is_space.c

SRC_SUBJECT_BOUNDARY =		check_validity_quotes.c \
							check_validity_semicolon.c \
							check_validity_backslash.c \
							check_validity_ascii_printable.c \
							check_subject_boundary.c \
							check_validity_less_great_and.c \
							check_validity_clobber.c \
							check_validity_bonus_andif_orif.c \
							get_reserved_word_array.c \
							put_subject_boundary_error_endl.c \
							check_subject_boudary_reserved_word.c \
							check_bonus_boundary.c

SRC_SIGNAL_HANDLER =		signal_handler.c \
							catch_eof_readline.c \
							register_signal_handler.c \
							register_heredoc_signal_handler.c \
							initialize_signal_act_array.c \
							heredoc_signal_handler.c \
							pipe_signal_handler.c \
							register_pipe_signal_handler.c \
							return_value_of_child.c \
							register_default_signal_handler.c \
							ignore_signal_handler.c 

SRC_PARSER =				parser.c \
							generate_envp_for_ast_tree.c \
							set_env_to_ast_node.c \
							get_control_string.c \
							set_control_to_ast_node.c \
							get_id_for_ast.c \
							set_id_to_ast_node.c \
							set_ast_type_string_to_ast_node.c \
							generate_args_array_for_ast_tree.c \
							set_args_to_ast_node.c \
							get_command_for_ast_tree.c \
							set_next_to_ast_node.c \
							set_command_to_ast_node.c \
							iter_lst_until_pipe.c \
							set_type_to_redirect_node.c \
							get_redirect_fd_length.c \
							set_memory_content_to_t_redirect_node.c \
							set_type_for_t_redirect_array.c \
							set_memory_content_to_t_redirect_array.c \
							set_t_redirect_element_to_array.c \
							set_op_to_redirect_fd_node.c \
							set_type_to_redirect_fd_node.c \
							set_content_to_redirect_fd_node.c \
							set_filename_to_redirect_fd_node.c \
							set_fd_to_redirect_fd.c \
							generate_filename_to_redirect_fd_type.c \
							generate_t_redirect_for_ast_tree.c \
							redisplay_t_redirect_array.c \
							printf_string_array.c \
							set_t_redirect_for_ast_node.c \
							go_to_t_redirect_for_ast_node.c \
							register_ast_element_to_garbage.c 

SRC_TERMINAL_CONTROL =		save_terminal_config.c \
							set_new_terminal_config.c \
							reset_terminal_config.c 

SRC_TERMINAL_MODE =			set_tty_mode.c \
							is_interactive_mode.c

SRC_GARBAGE_COLLECTOR = 	ft_malloc.c \
							get_garbage_addr.c \
							get_garbage.c \
							clear_garbage.c \
							ft_strdup_arc.c \
							ft_strjoin_arc.c \
							free_env_var_token.c \
							free_env_dupped.c \
							free_expand_lst.c \
							free_heredoc_list_and_erase_file.c \
							free_loop_main.c

SRC_RANDOM_GENERATOR =		random_name_generator.c \
							is_generate_random_number_prompted.c

SRC_LEXER =					lexer.c \
							prelexer_for_expand_prompt.c \
							remove_quotes.c \
							free_lexer_tokens.c \
							constructor/set_content_blank.c \
							constructor/set_content_operator.c \
							constructor/set_content_literal.c \
							constructor/set_end_of_token.c \
							constructor/set_head_of_token.c \
							specify_token_type_operator.c \
							is_having_hdoc_inside_token_lst.c \
							is_redirect_fd_having_filename.c \
							is_op_of_redirect_fd.c \
							is_having_redirect_op_inside_list.c \
							remove_quotes_and_retokenize_string_part.c \
							set_token_type_for_redirect_fd_filename.c \
							next_lexed_list_has_pipe.c \
							tokenize_prompt.c \
							convert_prelexed_to_str.c \
							set_token_type_for_command.c \
							set_token_type_for_argument.c \
							free_the_prompt.c \
							convert_token_limiter_to_token_filename.c \
							refresh_prompt_after_expand.c \
							reg_to_expand_lst.c \
							check_syntax_pipe.c \
							case_is_digit_set_content.c
	
SRC_LEXER__HEREDOC =		heredoc_prompt_writer.c \
							is_heredoc_having_limiter.c \
							main_heredoc.c \
							register_heredoc.c \
							request_prompt_heredoc_from_list.c \
							set_token_type_for_heredoc_limiter.c \
							free_heredoc_list.c \
							warn_heredoc_ctrl_d.c \
							reg_heredoc_garbage.c \
							get_heredoc_garbage_lst.c \
							hdoc_line_need_expand.c \
							expand_heredoc.c \
							get_fd_open.c \
							get_previous_counted_line_from_file.c \
							set_previous_counted_line_from_file.c \
							remove_counted_line.c

SRC_LEXER__UTILS =			prompt_need_expand.c \
							is_char_allowed_env_var.c \
							get_last_char_lexed.c \
							debug_local_print_lexer_prompt.c \
							is_metachar.c \
							get_chartype_id.c \
							is_t_list_el_operator.c \
							convert_op_type.c \
							get_next_token_not_blank.c \
							get_next_token_type_from_lst_el.c \
							is_limiter_expandable.c \
							count_char_when_unquoted.c \
							strncpy_with_quotes_rules.c \
							printf_all_lexer_token_t_list.c  
							
							

SRC_AST__NODE_HANDLER =		create_node.c \
							get_type_to_string.c \
							get_type_to_int.c \
							set_token.c \
							array_string_length.c \
							set_string_type.c \
							set_string_ast_type.c \
							get_ast_type_to_string.c \
							get_ast_type_to_int.c \
							free_ast.c 

SRC_AST__ARGUMENT_EXTRACT =	extract_args_array_from_token_list.c \
							count_args_array_size.c \
							skip_parsed_after_extraction_args.c
							
SRC_AST__PARSER_UTILS = 	lexer_next_is_op.c \
							get_spec_op_value.c 

SRC_ERROR_HANDLER = 		is_error.c \
							get_error_array.c \
							set_error_state.c 

SRC_HISTORY_MANAGER =		add_prompt_to_history.c \
							load_history_from_file.c 

SRC_GNL =					get_next_line_utils.c \
							get_next_line.c \
							get_next_line_need_free.c 

SRC_PROMPT_HANDLER =		get_display_prompt.c \
							is_prompt_empty.c \
							is_last_elem_is_pipe.c \
							prompt_selector.c \
							pipe_prompt_handler.c

SRC_INIT =					initialize_minishell.c \
							set_shell_level.c \
							loading_minishell.c

SRC_MINISHELL = 			main.c 

SRC_EXECUTION =				execution.c \
							ft_split.c \
							ft_strjoin.c \
							input_redirection.c \
							input_redirection_2.c \
							minishell_add_path.c \
							output_redirection.c \
							output_redirection_2.c \
							path_management_2.c \
							path_management.c \
							pipex_utils.c \
							pipex_utils_2.c \
							pipex_utils_3.c \
							print.c \
							init_builtin.c \
							forks_creation.c \
							pipes_creation.c \
							fd_related.c \
							builtin_file.c \
							exec_struct_init.c \
							checking_functions.c \
							exiting_functions.c

SRC_EXECUTION__BUILTIN =	echo_file.c \
				cd_file.c \
				pwd_file.c \
				export_file.c \
				export_file_2.c \
				unset_file.c \
				env_file.c \
				exit_file.c \
				exit_file_2.c



FULL_PATH_UTILS = $(addprefix $(F_UTILS), $(shell echo $(SRC_UTILS)))
FULL_PATH_UTILS__GETTERS = $(addprefix $(F_UTILS__GETTERS), $(shell echo $(SRC_UTILS__GETTERS)))
FULL_PATH_UTILS__SETTERS = $(addprefix $(F_UTILS__SETTERS), $(shell echo $(SRC_UTILS__SETTERS)))
FULL_PATH_ENV_PARSE = $(addprefix $(F_ENV_PARSE), $(shell echo $(SRC_ENV_PARSE)))
FULL_PATH_ENV_HANDLER = $(addprefix $(F_ENV_HANDLER), $(shell echo $(SRC_ENV_HANDLER)))
FULL_PATH_CTYPE = $(addprefix $(F_CTYPE), $(shell echo $(SRC_CTYPE)))
FULL_PATH_SUBJECT_BOUNDARY = $(addprefix $(F_SUBJECT_BOUNDARY), $(shell echo $(SRC_SUBJECT_BOUNDARY)))
FULL_PATH_SIGNAL_HANDLER = $(addprefix $(F_SIGNAL_HANDLER), $(shell echo $(SRC_SIGNAL_HANDLER)))
FULL_PATH_PARSER = $(addprefix $(F_PARSER), $(shell echo $(SRC_PARSER)))
FULL_PATH_TERMINAL_CONTROL = $(addprefix $(F_TERMINAL_CONTROL), $(shell echo $(SRC_TERMINAL_CONTROL)))
FULL_PATH_GARBAGE_COLLECTOR = $(addprefix $(F_GARBAGE_COLLECTOR), $(shell echo $(SRC_GARBAGE_COLLECTOR)))
FULL_PATH_RANDOM_GENERATOR = $(addprefix $(F_RANDOM_GENERATOR), $(shell echo $(SRC_RANDOM_GENERATOR)))
FULL_PATH_LEXER = $(addprefix $(F_LEXER), $(shell echo $(SRC_LEXER)))
FULL_PATH_LEXER__HEREDOC = $(addprefix $(F_LEXER__HEREDOC), $(shell echo $(SRC_LEXER__HEREDOC)))
FULL_PATH_LEXER__UTILS = $(addprefix $(F_LEXER__UTILS), $(shell echo $(SRC_LEXER__UTILS)))
FULL_PATH_AST__NODE_HANDLER = $(addprefix $(F_AST__NODE_HANDLER), $(shell echo $(SRC_AST__NODE_HANDLER)))
FULL_PATH_AST__ARGUMENT_EXRACT = $(addprefix $(F_AST__ARGUMENT_EXTRACT), $(shell echo $(SRC_AST__ARGUMENT_EXTRACT)))
FULL_PATH_AST_PARSER_UTILS = $(addprefix $(F_AST__PARSER_UTILS), $(shell echo $(SRC_AST__PARSER_UTILS)))
FULL_PATH_ERROR_HANDLER = $(addprefix $(F_ERROR_HANDLER), $(shell echo $(SRC_ERROR_HANDLER)))
FULL_PATH_HISTORY_MANAGER = $(addprefix $(F_HISTORY_MANAGER), $(shell echo $(SRC_HISTORY_MANAGER)))
FULL_PATH_GNL = $(addprefix $(F_GNL), $(shell echo $(SRC_GNL)))
FULL_PATH_PROMPT_HANDLER = $(addprefix $(F_PROMPT_HANDLER), $(shell echo $(SRC_PROMPT_HANDLER)))
FULL_PATH_INIT = $(addprefix $(F_INIT), $(shell echo $(SRC_INIT)))
FULL_PATH_MINISHELL = $(addprefix $(F_MINISHELL), $(shell echo $(SRC_MINISHELL)))
FULL_PATH_EXECUTION = $(addprefix $(F_EXECUTION), $(shell echo $(SRC_EXECUTION)))
FULL_PATH_EXECUTION__BUILTIN = $(addprefix $(F_EXECUTION__BUILTIN), $(shell echo $(SRC_EXECUTION__BUILTIN))) 
FULL_PATH_TERMINAL_MODE= $(addprefix $(F_TERMINAL_MODE), $(shell echo $(SRC_TERMINAL_MODE)))


ALL_SRC = $(FULL_PATH_MINISHELL) \
		$(FULL_PATH_INIT) \
		$(FULL_PATH_PROMPT_HANDLER) \
		$(FULL_PATH_GNL) \
		$(FULL_PATH_HISTORY_MANAGER)\
		$(FULL_PATH_ERROR_HANDLER) \
		$(FULL_PATH_AST__ARGUMENT_EXRACT) \
		$(FULL_PATH_AST__NODE_HANDLER) \
		$(FULL_PATH_AST_PARSER_UTILS) \
		$(FULL_PATH_LEXER) \
		$(FULL_PATH_LEXER__HEREDOC) \
		$(FULL_PATH_LEXER__UTILS) \
		$(FULL_PATH_RANDOM_GENERATOR) \
		$(FULL_PATH_GARBAGE_COLLECTOR) \
		$(FULL_PATH_TERMINAL_CONTROL) \
		$(FULL_PATH_PARSER) \
		$(FULL_PATH_SIGNAL_HANDLER) \
		$(FULL_PATH_CTYPE) \
		$(FULL_PATH_SUBJECT_BOUNDARY) \
		$(FULL_PATH_ENV_PARSE) \
		$(FULL_PATH_ENV_HANDLER) \
		$(FULL_PATH_UTILS) \
		$(FULL_PATH_UTILS__GETTERS) \
		$(FULL_PATH_UTILS__SETTERS) \
		$(FULL_PATH_EXECUTION) \
		$(FULL_PATH_EXECUTION__BUILTIN)\
		$(FULL_PATH_TERMINAL_MODE)

OBJ = $(ALL_SRC:%.c=%.o)

.PHONY : all clean fclean re
all : $(NAME)

display_hello:
	@echo "minishell by eamar and apayet"

display_test:
	echo Hello

$(NAME): display_hello $(OBJ) $(DEP)
	@make object_creation -s -C .
	@make all -s -C libcolor
	@make all -s -C libftprintf
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

object_creation : $(DEP) $(OBJ)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n .
clean :
	@make clean -s -C libcolor
	@make clean -s -C libftprintf
	@rm -f  $(OBJ)

fclean :
	@make fclean -s  -C libcolor
	@make fclean -s -C libftprintf
	@make  clean -s -C .
	@rm -f $(NAME)

valgrind : all 
	# make clean
	valgrind --suppressions=valgrind_leak_suppress_realine_error --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --verbose ./minishell
test_split_bash:
	@gcc test_args_counter_for_shell.c -o count_me
	@echo "use $>count_me [args] for know how many string is splitted when bash parse"

re :
	@make fclean -s  -C .
	@make all -s -C .
