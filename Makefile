
NAME	= pipex

LIBNAME	= libft.a

CC 	= gcc

FLAGS 	= -Wall -Werror -Wextra -I .

ARRC	= ar rcs

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

$(NAME)			: ${LIBNAME}
				@echo "$(MAGENTA) --------------------------COMPILING ./PIPEX-------------------------- $(CYAN)"
				@echo "\n"
				${CC} ${FLAGS} *.c ${LIBNAME} -o ${NAME}
				@echo "\n"
				@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"

${LIBNAME}	: 
				make -C libft
				@echo "$(MAGENTA) --------------------------COMPILING LIBFTPIPEX.A-------------------------- $(CYAN)"
				@echo "\n"
				cp libft/libft.a .
				@echo "\n"
				@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"


clean			:
				@make clean -C libft
				@echo "$(MAGENTA) --------------------------CLEANING PIPEX OBJECTS-------------------------- $(CYAN)"
				@echo "\n"
				${RM} ${OBJS}
				@echo "\n"
				@echo "$(GREEN) --------------------------DONE--------------------------$(DEF_COLOR)"

fclean			: clean
				@make fclean -C libft
				@echo "$(MAGENTA) --------------------------REMOVING libftpipex.a-------------------------- $(CYAN)"
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
		