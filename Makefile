SRCS	= ft_extract.c\
			ft_pathsort.c\
			ft_processes.c\
			ft_compare.c\

OBJS	= ft_extract.o\
			ft_pathsort.o\
			ft_processes.o\
			ft_compare.o\

NAME	= pipex

LIBNAME	= libftpipex.a

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
				${CC} ${FLAGS} mainpipex.c ${LIBNAME} -o ${NAME}
				@echo "\n"
				@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"

${LIBNAME}	: ${OBJS}
				make -C libft
				@echo "$(MAGENTA) --------------------------COMPILING LIBFTPIPEX.A-------------------------- $(CYAN)"
				@echo "\n"
				cp libft/libft.a .
				mv libft.a libftpipex.a
				${ARRC} libftpipex.a ${OBJS}
				@echo "\n"
				@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"

%.o				: %.c
				@echo "$(MAGENTA)"
				${CC} ${FLAGS} -c $< -o $@

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