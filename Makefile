RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap
CHECKER = checker
FILE_M = main moves ft_atoi check_args utils ft_split funct_helper isA_sorted sort_small_stack sort_arr push_swap helper_function moves2 helper2_function
FILE_B = bonus/check_args bonus/checker_moves bonus/checker_moves2 bonus/checker_utils bonus/checker bonus/funct_helper bonus/ft_split bonus/utils
HEADER = push_swap.h 
HEADER_B = bonus/checker.h
HEADER_G = gnl/get_next_line.h
GNL = gnl/get_next_line gnl/get_next_line_utils

SRCS_M = $(addsuffix .c, $(FILE_M))
OBJS_M = $(addsuffix .o, $(FILE_M))
SRCS_B = $(addsuffix .c, $(FILE_B))
OBJS_B = $(addsuffix .o, $(FILE_B))
SRCS_G = $(addsuffix .c, $(GNL))
OBJS_G = $(addsuffix .o, $(GNL))


%.o : %.c $(HEADER)
	@echo "$(BLUE)Building project ⏳.."
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus/%.o :bonus/%.c $(HEADER_B)
	@echo "$(BLUE)Building project ⏳.."
	@$(CC) $(CFLAGS) -c -o $@ $<

gnl/%.o :gnl/%.c $(HEADER_G)
	@echo "$(BLUE)Building project ⏳.."
	@$(CC) $(CFLAGS) -c -o $@ $<
	
all : $(NAME)
	@echo  "$(GREEN)Mandatory done successfully ✅"

$(NAME): $(OBJS_M) 
	@$(CC) $(OBJS_M) -o $(NAME)

$(CHECKER) : $(OBJS_B) $(HEADER_B) $(OBJS_G)
	@$(CC) $(OBJS_B)  $(OBJS_G)  -o $(CHECKER)
	
bonus : $(CHECKER)
		@echo  "$(GREEN)Bonus done successfully ✅"

clean:
	@$(RM) $(OBJS_M) $(OBJS_B) $(OBJS_G)
	@echo  "$(RED)ALL DELETED ☠ "

fclean: clean
	@$(RM) $(NAME) $(CHECKER)

re: fclean all 

.PHONY: all clean fclean re bonus