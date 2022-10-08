CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g3 #-fsanitize=address
NAME =		libcolor.a
SRC = 		colors.c
OBJ =		$(SRC:%.c=%.o)
AR =		ar
ARFLAGS =	-rcs

all: $(NAME)

$(OBJ) : ./libcolors.h

$(NAME) :
	@make compile_obj -C .
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n .

compile_obj : $(OBJ)
	@echo ""
clean:
	@rm -rf $(OBJ)

fclean:
	@make clean -C .
	@rm -rf $(NAME)

re:
	@make flcean -C .
	@make all -C .

.PHONY: all clean fclean re
