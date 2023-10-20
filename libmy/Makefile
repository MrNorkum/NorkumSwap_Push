NAME = libmy.a
AR = ar rc
CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG) -c
RM = rm -rf
MKDIR = mkdir -p
OBJDIR = OBJECTS


SRC = 	./my_split.c		\
 		./my_strchr.c 		\
 		./my_strdup.c		\
 		./my_strjoin.c 		\
		./my_strlcpy.c		\
 		./my_strlen.c 		\
 		./my_strncmp.c 		\
		./my_substr.c		\
		./my_printf.c		\
		./my_sort_int_tab.c	\
		./get_line.c

OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))

$(OBJDIR)/%.o:  %.c
	@$(MKDIR) $(OBJDIR)
	@$(CMPL) $< -o $@

all: $(NAME)
a: all

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

c: clean
clean:
	@$(RM) $(OBJDIR)

f: fclean
fclean : clean
	@$(RM) $(NAME)

re: fclean all

r:
	@make re
	@make clean

n: norm
norm:
	@norminette

.PHONY: all clean fclean re bonus
