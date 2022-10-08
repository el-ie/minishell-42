CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
AR = ar
ARFLAGS = -rcs
NAME = libft.a
SRC= ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_memmove.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c 

OBJECT = $(SRC:%.c=%.o)

all : $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n .

$(NAME) :
	@make compile_objs -C .
	@$(AR) $(ARFLAGS) $(NAME) $(OBJECT) $(OBJ_BONUS)

compile_objs: $(OBJECT)
	@echo ""
clean:
	@/bin/rm -f $(OBJECT) $(OBJ_BONUS) $(NAME)

fclean: 
	@make clean -C .
	@/bin/rm -f  $(NAME)

re:
	@make fclean -C .
	@make all -C .

.PHONY: all clean fclean re compile_objs
