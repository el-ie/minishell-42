/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:43:54 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:24:40 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

char			*lexer(char	*prompt);
char			get_last_char_lexed(t_list *cur);
int				prompt_need_expand(char *prompt);
void			case_is_digit_set_content(t_prelex_state *state);
char			*prelexer_for_expand_prompt(char *p_prompt);
int				is_char_allowed_env_var(char c);
char			*convert_prelexed_to_str(t_list *list);

void			printf_all_lexer_token_t_list(void);
void			debug_local_print_lexer_prompt(t_lexer_prompt *state);
int				is_metachar(char c);
int				get_chartype_id(char c);
void			set_head_of_token(t_lexer_prompt *state, t_lexer_token *node);
int				set_end_of_token(t_lexer_prompt *state, t_lexer_token **p_node);
void			set_content_literal(t_lexer_prompt *state, t_lexer_token *node);
void			set_content_operator(t_lexer_prompt *stte, t_lexer_token *node);
void			set_content_blank(t_lexer_prompt *state, t_lexer_token *node);
void			tokenize_prompt(char *prompt);
int				is_t_list_el_operator(t_list *cur);
void			convert_op_type(t_list *cur);
void			specify_token_type_operator(void);
int				is_having_hdoc_inside_token_lst(void);
int				is_redirect_fd_having_filename(void);

int				is_op_of_redirect_fd(int type);
int				is_having_redirect_op_inside_list(void);
void			set_token_type_for_redirect_fd_filename(void);
int				check_subject_boundary_reserved_word(void);
int				next_lexed_list_has_pipe(t_list *cur);
void			set_token_type_for_argument(void);
char			*free_the_prompt(char **p_prompt);
char			*refresh_prompt_after_expand(char **new_prompt, char **prompt);
void			convert_token_limiter_to_token_filename(void);
char			*reg_to_expand_lst(char *elem);
int				check_syntax_pipe(char *prompt);

//heredoc functions
int				get_previous_counted_line_from_file(void);
void			set_previous_counted_line_from_file(int nbr);
void			remove_counted_line(char *filename);
void			heredoc_prompt_writer(t_heredoc *hdoc);
int				is_heredoc_having_limiter(void);
int				hdoc_line_need_expand(char *content);
int				get_fd_open(int fd);
void			register_heredoc(void);
char			*expand_heredoc(char *p_content);
void			request_prompt_heredoc_from_list(void);
void			set_token_type_for_heredoc_limiter(void);
t_lexer_token	*get_next_lexer_token_not_blank(t_list *el);
int				get_next_token_type_from_lst_el(t_list *el);
void			free_heredoc_list(void);
int				main_heredoc(void);
void			warn_heredoc_ctrl_d(t_heredoc *hdoc, int current_count);
char			*reg_heredoc_garbage(char *ref, int is_reset);
t_list			*get_heredoc_garbage_lst(t_list *lst);
char			*remove_quotes(char *str);
void			strncpy_with_quotes_rules(char *dest, char *str);
int				count_char_when_unquoted(char *str);
int				is_limiter_expandable(char *limiter);
void			free_lexer_tokens(void);
int				remove_quotes_and_retokenize_string_part(void);
void			set_token_type_for_command(void);

#endif
