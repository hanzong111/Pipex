SRCS	= ft_extract.c\
			ft_pathsort.c\
			ft_processes.c\
			ft_compare.c\
			mainpipex.c

NAME	= pipex

LIBNAME	= libft.a

CC 	= gcc

FLAGS 	= -Wall -Werror -Wextra -I .

RM		= rm -rf 

DEF_COLOR     = \033[0;39m
GRAY         = \033[0;90m
RED         = \033[0;91m
GREEN         = \033[0;92m
YELLOW         = \033[0;93m
BLUE         = \033[0;94m
MAGENTA     = \033[0;95m
CYAN         = \033[0;96m
WHITE         = \033[0;97m

all		: ${NAME}

$(NAME)			: ${SRCS} | ${LIBNAME}
				@echo "$(MAGENTA) --------------------------COMPILING ./PIPEX-------------------------- $(CYAN)"
				@echo "\n"
				${CC} ${FLAGS} ${SRCS} ${LIBNAME} -o ${NAME}
				@echo "\n"
				@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"
				
				@echo "$(GREEN) ----------------$(RED)I $(CYAN)AM $(GREEN)NOT $(YELLOW)RUDE$(GREEN)---------------------------- $(DEF_COLOR)"

${LIBNAME}		:
				@echo "$(MAGENTA) --------------------------COMPILING LIBFT.A-------------------------- $(CYAN)"
				@echo "\n"
				make -C libft
				cp libft/libft.a .
				@echo "\n"
				@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"

clean			:
				make clean -C libft

fclean			: clean
				make fclean -C libft
				@echo "$(MAGENTA) --------------------------REMOVING libft.a-------------------------- $(CYAN)"
				@echo "\n"
				${RM} ${LIBNAME}
				@echo "\n"
				@echo "$(GREEN) --------------------------DONE--------------------------$(DEF_COLOR)"
				@echo "$(MAGENTA) --------------------------REMOVING ./pipex-------------------------- $(CYAN)"
				@echo "\n"
				${RM} ${NAME}
				@echo "\n"
				@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"

re			: fclean all

.PHONY		:all clean fclean re