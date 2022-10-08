CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
AR = ar
ARFLAGS = -rcs
DEPENDENCY = libft.a
LIBFT_PATH = ./libft/
NAME = libftprintf.a

SRC_GETTER =	ft_get_char.c \
				ft_get_string.c \
				ft_get_pointer.c \
				ft_get_digit.c \
				ft_get_ignore_spec.c \
				ft_get_uint.c \
				ft_get_x.c

SRC_ADAPTER =	ft_convert_p_format.c \
				ft_convert_c_format.c \
				ft_convert_s_format.c \
				ft_convert_di_format.c \
				ft_convert_u_format.c \
				ft_convert_x_format.c \
				ft_ignore_specifier_format.c

SRC_UTILS =		ft_uintlen.c \
				ft_check_spec_f.c \
				ft_init_payload.c \
				ft_clean_payload.c \
				ft_put_uint_fd.c \
				ft_itoa_base.c \
				ft_intlen.c
SRC_CTRL =		ft_funct_handler.c \
				ft_va_arg_handler.c

SRC =			ft_printf.c

PREFIX_SRC = ./
PREFIX_GET = ./getters/
PREFIX_ADAPT = ./adapter/
PREFIX_UTILS = ./utils/
PREFIX_CTRL = ./controller/
_PATHS = ./objects/
MKDIR = mkdir
RM = /bin/rm
MV = /bin/mv

FULL_PATH_SRC = $(addprefix $(PREFIX_SRC), $(shell echo $(SRC)))

FULL_PATH_GET =  $(addprefix $(PREFIX_GET), $(shell echo $(SRC_GETTER)))

FULL_PATH_UTILS =  $(addprefix $(PREFIX_UTILS), $(shell echo $(SRC_UTILS)))

FULL_PATH_ADPT =  $(addprefix $(PREFIX_ADAPT), $(shell echo $(SRC_ADAPTER)))

FULL_PATH_CTRL = $(addprefix $(PREFIX_CTRL), $(shell echo $(SRC_CTRL)))

ALL_SRC =	$(FULL_PATH_SRC) \
			$(FULL_PATH_GET) \
			$(FULL_PATH_UTILS) \
			$(FULL_PATH_ADPT) \
			$(FULL_PATH_CTRL) 

OBJ = $(ALL_SRC:%.c=%.o)

.PHONY: all clean fclean re 
all : $(NAME)

$(NAME):
	@make libft_dep -C .
	@make compile_obj -C .
	@$(AR) $(ARFLAGS) libpartialprintf.a $(OBJ)
	@$(AR) -rcT $(NAME) libft/libft.a libpartialprintf.a 

compile_obj: $(OBJ) libft_dep
	@echo
libft_dep:
	@make all -C libft

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n .

clean:
	@make clean -C libft
	@rm -f libpartialprintf.a
	@rm -f $(OBJ)
fclean: 
	@make clean -C .
	@make fclean -C libft
	@rm -f $(NAME)

re: 
	@make fclean -C .
	@make all -C .

