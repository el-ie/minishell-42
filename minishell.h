/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:20:48 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 00:15:57 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h> 
# define _GNU_SOURCE
# define BONUS 0
# define DEBUG 0

# include "./include/execution.h"

# include "./include/enum.h"
# include "./include/structure.h"
# include "./include/ast.h"
# include "./include/utils.h"
# include "./include/garbage_collector.h"
# include "./include/error.h"
# include "./libftprintf/libftprintf.h"
# include "./libcolor/libcolors.h"
# include "./include/prompt_handler.h"
# include "./include/lexer.h"
# include "./include/parser.h"
# include "./include/init.h"
# include "./include/get_next_line.h"
# include "./include/history_manager.h"
# include "./include/ctypes.h"
# include "./include/subject_boundary.h"
# include "./include/signal_handler.h"
# include "./include/terminal_control.h"

# include "./include/terminal_mode.h"

# include <linux/limits.h>

typedef struct s_gate
{
	int				pid;
	int				input;
	int				output;
	int				validity;
	int				nb;
	char			**cmd;
	char			*path;
	struct s_gate	*next;
	struct s_gate	*back;
}				t_gate;

typedef struct s_access_test
{
	int		exist;
	int		exec;
	char	*path;
	char	*path_denied;

}				t_access_test;

int			is_generate_random_number_prompted(char *prompt);
char		*random_name_generator(unsigned int length_file_name, int hidden);
void		create_minimal_env(void);
void		parse_env(void);
t_list		*get_env_t_list(void);
void		init_vars(size_t *k_len, int *f_key, int *sub, const char *key);
void		new_env_var_lex_token(const char *key_or_value, t_lexer_token *tok);
int			is_var_exist_in_env(const char *key);
char		*get_env_value(const char *key);
int			do_cmp_env(const char *key, t_env_var_token *content);
int			is_cmp_perfect_match(int key_length, t_env_var_token *content);
int			is_env_token_malloced(const char *key);
void		set_env_by_var_name(const char *key, const char *value);
void		remove_env_var_if_exist(const char *key);
void		printf_all_env_t_list(void);
char		**export_env_to_array(void);
void		set_up_content(void **p_c, int f_key, char *key, char *value);
void		subtoken_update(t_env_var_token **p_content, int sub_tokenized);

char		**extract_args_array_from_token_list(t_list *node);
size_t		count_args_array_size(t_list *node);
void		skip_parsed_after_extraction_args(t_list **partial_lst);
int			lexer_next_is_op(t_list *lexer_node);

size_t		get_token_length(t_lexer_token *token);
int			check_if_char_is_in_str(const char *str, char c);
int			count_until_char_found(const char *str, char c);
void		sub_tokenisation(char *line, t_list **head, t_state_lex_env *env_c);
t_list		**get_env_t_list_addr(void);
int			check_end_of_value(t_lexer_token *token);

/* Elie */

void		display_cmds(t_ast *ast);
void		free_key_and_value(char **key, char **value);
void		save_access_problem_cmd(t_ast *ast, char *path, char *path_denied);
void		save_access_problem_path(t_ast *ast, int exist, int exec);
void		save_command_validity(t_ast *ast);
void		launch_exec_valid_cmd(t_ast *ast, t_ast *list_cmd, t_data *data);
void		wait_processes_save_status(t_data *data);
void		fork_failure(t_data *data, t_ast *last_ast);
void		remove_text(char *filename);
void		check_if_cmd_empty(t_ast *ast);
void		check_if_builtin(t_data *data, t_ast *ast);
void		check_if_directory(t_ast *ast);
void		check_if_cmd_null(t_ast *ast);
void		init_exec_struct(t_ast *ast);
void		apply_redirections_input(t_ast *ast);
void		output_management(t_redirect *output, t_ast *ast);
void		input_management(t_redirect *input, t_ast *ast);
void		exit_save_status(int exit_code);
void		save_status_free_exec_clean_exit(int exit_code);
void		free_exec_clean_exit(void);
void		free_exec_struct(t_ast *ast);
void		launch_builtin(t_data *data, t_ast *ast);
void		init_builtin(t_data *data);
void		close_previous_fds(t_gate *elem);
void		ft_close(int fd, char *str);
void		wait_close_fds_free_liste_exit(t_gate **liste);
void		close_all_fds(t_ast *ast);
void		close_other_fds(t_gate *liste, int input, int output);
void		launch_exec(t_ast *ast, t_ast *list_cmd, t_data *data);
void		close_more(void);
void		lst_addfront_fake(t_gate **liste, t_gate *fake);
void		only_spaces(char *str, t_gate **liste);
void		fill_list(t_gate **liste, char **argv, char **envp);
void		lst_addback(t_gate **liste, t_gate *new_el);
void		free_liste(t_gate **liste);
void		display(t_gate *liste);
void		free_path(char **path);
void		exist_no_access(char **path, char **path_denied);
void		init_access_struct(t_access_test *acc);
void		ft_access_message(char *path, char *path_denied, char *cmd);
void		free_paths(char **paths);
void		ft_exit(char *str, int error);
void		ft_frexit(t_gate **liste, char *str, int error);
void		ft_dup2(int fd1, int fd2);
void		free_cmd(char **cmd);
void		print_not_found(char *cmd);
void		print_permission_denied(char *path_denied);
void		of_write_permission(char *output_file, t_gate **liste, int in_fd);
void		find_cmd_path_and_check_validity(t_ast *list_cmd);
void		apply_redirections_output(t_ast *ast);
int			valid_export_argument(char *str);
int			ft_is_num(char c);
int			valid_identifier(char *str, char *builtin_name);
int			builtin_unset(char **args, t_ast *ast, t_data *data);
int			builtin_exit(char **args, t_ast *ast, t_data *data);
int			builtin_pwd(char **args, t_ast *ast, t_data *data);
int			builtin_export(char **args, t_ast *ast, t_data *data);
int			builtin_env(char **args, t_ast *ast, t_data *data);
int			builtin_cd(char **args, t_ast *ast, t_data *data);
int			builtin_echo(char **args, t_ast *ast, t_data *data);
int			get_builtin_index(char *cmd, char *builtin_list[8]);
int			is_standart_fd(int fd);
int			pipe_error(t_ast *last_ast);
int			is_input_operator(int type);
int			add_pipes(t_ast *ast);
int			launch_forks(t_data *data, t_ast *list_cmd);
int			get_output_file(char **argv, t_gate **liste, int input_file);
int			get_input_file(char **argv, t_gate **liste);
int			do_heredoc(char *limiter, t_gate **liste);
int			isnt_limiter(char *str, char *limiter);
int			is_heredoc(char *s1, char *s2);
int			ft_strlen_pipex(const char *str);
int			is_it_path(char *envp, char *str);
int			is_path(char *str);
int			never(void);
int			not_only_spaces(char *str);
int			ft_strcmp(char *s1, char *s2);
int			output_file_exist(char *output_file);
int			input_file_permissions(char *str);
int			execution(void);//minishell
int			just_one_builtin(t_ast *ast);
int			same(char *s1, char *s2);
int			test_input_access(t_redirect *input);
int			input_correct_access(t_ast *ast);
int			another_pipe(t_ast *ast);
int			is_cmd(t_ast *ast);
int			is_output_operator(int type);
int			output_presence(t_ast *ast);
int			test_output_access(t_redirect_fd *redirect);
int			test_access_and_create_files(t_ast *ast);
int			input_presence(t_ast *ast);
char		**ft_split(char const *s, char c);
char		**ft_split_slash(char const *s, char c, int q);
char		*ft_strdup(const char *s);
char		*ft_strjoin_pipex(char *s1, char *s2);
char		*free_and_return(char *s1, char *s2, char *str);
char		*ft_strjoin_pipex_nofree(char *s1, char *s2);
char		*get_second_file(char **argv);
char		**white_spaces_cmd(char *str);
char		**get_paths(char **envp);
char		*find_path(char **paths, char *cmd, t_ast *ast);
char		*get_the_path(char **paths, char *cmd, t_ast *ast, int i);
char		**cmd_and_args(t_ast *ast);
t_redirect	*get_next_input_node(t_ast *ast, int *i);
t_redirect	*get_last_input(t_ast *ast);
t_redirect	*get_next_output_node(t_ast *ast, int *i);
t_redirect	*get_last_output(t_ast *ast);
t_gate		*get_last(t_gate *iter);
t_gate		*lstnew(char **cmd, char *path);
t_gate		*lstnew_fakecmd(char **cmd, char *path);
t_ast		*get_next_pipe(t_ast *ast);

#endif
