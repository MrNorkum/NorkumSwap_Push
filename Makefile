NAME = swap_push.a
BONUS = checker
BONUS_SRC = checker.c
PUSH_SWAP = swap_push
MAIN_SRC = main.c
LIBMY_PATH = ./libmy
LIBMY = $(LIBMY_PATH)/libmy.a
AR = ar rc
CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG) -c

RM = rm -rf
MKDIR = mkdir -p

SRC =	source.c	\
		source1.c	\
		source2.c	\
		quicksort.c

OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
OBJDIR = OBJECTS

$(OBJDIR)/%.o:  %.c
	@$(MKDIR) $(OBJDIR)
	@$(CMPL) $< -o $@

all: $(NAME)
a: all

$(NAME): $(OBJ)
	@make -C $(LIBMY_PATH) all
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) $(FLAG) $(NAME) $(LIBMY) $(MAIN_SRC) -o $(PUSH_SWAP)

b: bonus
bonus: $(OBJ)
	@make -C $(LIBMY_PATH) all
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) $(FLAG) $(NAME) $(LIBMY) $(MAIN_SRC) -o $(PUSH_SWAP)
	@$(CC) $(FLAG) $(NAME) $(LIBMY) $(BONUS_SRC) -o $(BONUS)

c: clean
clean:
	@make -C $(LIBMY_PATH) clean
	@$(RM) $(OBJDIR)

f: fclean
fclean :
	@make -C $(LIBMY_PATH) fclean
	@$(RM) $(OBJDIR)
	@$(RM) $(PUSH_SWAP)
	@$(RM) $(BONUS)
	@$(RM) $(NAME)

re: fclean all

r:
	@make re
	@make clean

n: norm
norm:
	@norminette

.PHONY: all clean fclean re bonus

