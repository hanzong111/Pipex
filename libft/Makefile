

SRCS =	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_substr.c\
		ft_split.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		get_next_line_utils.c\
		get_next_line.c

INCLUDES = .

OBJS	= $(SRCS:.c=.o)

BONUS	= ft_lstnew.c\
		  ft_lstadd_front.c\
		  ft_lstsize.c\
		  ft_lstlast.c\
		  ft_lstadd_back.c\
		  ft_lstdelone.c\
		  ft_lstclear.c\
		  ft_lstiter.c\
		  ft_lstmap.c
		  
BONUSOBJS = $(BONUS:.c=.o)

NAME		= libft.a

FLAGS	= -Wall -Wextra -Werror -c

CC = gcc

LIB = ar rcs

CLEAN = rm -f ${OBJS} ${BONUSOBJS}

FCLEAN = rm -f $(NAME)

all :	$(NAME)

$(NAME) : ${OBJS}
		make -C ft_printf
		cp ft_printf/libftprintf.a .
		mv libftprintf.a ${NAME}
		${LIB} $(NAME) ${OBJS}
	
%.o: %.c
		${CC} ${FLAGS} -I ${INCLUDES} $< -o ${<:.c=.o} 

clean : 
		make clean -C ft_printf
		${CLEAN}

fclean : clean
		make fclean -C ft_printf
		${FCLEAN}

bonus : ${BONUSOBJS}
		${LIB} $(NAME) ${BONUSOBJS}

re :	fclean all
