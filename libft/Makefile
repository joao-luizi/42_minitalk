
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
LIBC = ar rcs
RM = rm -f

OBJDIR = ./obj
SRCDIR = ./src
LIBDIR = ./lib


#SRCS := $(shell find ${SRCDIR} -type f -name "*.c")
SRCS =	./src/ft_printf/ft_c_handler.c ./src/ft_printf/ft_d_handler.c ./src/ft_printf/ft_p_handler.c ./src/ft_printf/ft_s_handler.c \
		./src/ft_printf/ft_u_handler.c ./src/ft_printf/ft_x_handler.c ./src/ft_printf/ft_printf.c ./src/ft_printf/ft_utils.c 		\
		./src/ft_printf/ft_utils2.c ./src/ft_printf/ft_utils3.c ./src/ft_printf/ft_utils4.c ./src/ft_printf/ft_utils5.c 			\
		./src/ft_printf/ft_utils6.c 																								\
		./src/gnl/get_next_line.c ./src/gnl/get_next_line_utils.c																	\
		./src/libft/ft_atoi.c ./src/libft/ft_bzero.c ./src/libft/ft_calloc.c ./src/libft/ft_isalnum.c ./src/libft/ft_isalpha.c 		\
		./src/libft/ft_isascii.c ./src/libft/ft_isdigit.c ./src/libft/ft_isprint.c ./src/libft/ft_itoa.c ./src/libft/ft_lstadd_back.c 			\
		./src/libft/ft_lstadd_front.c ./src/libft/ft_lstclear.c ./src/libft/ft_lstdelone.c ./src/libft/ft_lstiter.c 				\
		./src/libft/ft_lstlast.c ./src/libft/ft_lstmap.c ./src/libft/ft_lstnew.c ./src/libft/ft_lstsize.c ./src/libft/ft_memchr.c 	\
		./src/libft/ft_memcmp.c	./src/libft/ft_memcpy.c ./src/libft/ft_memmove.c ./src/libft/ft_memset.c 							\
		./src/libft/ft_putchar_fd.c	./src/libft/ft_putendl_fd.c ./src/libft/ft_putnbr_fd.c ./src/libft/ft_putstr_fd.c 				\
		./src/libft/ft_split.c ./src/libft/ft_strchr.c ./src/libft/ft_strdup.c ./src/libft/ft_striteri.c ./src/libft/ft_strjoin.c	\
		./src/libft/ft_strlcat.c ./src/libft/ft_strlcpy.c ./src/libft/ft_strlen.c ./src/libft/ft_strmapi.c ./src/libft/ft_strncmp.c	\
		./src/libft/ft_strnstr.c ./src/libft/ft_strrchr.c ./src/libft/ft_strtrim.c ./src/libft/ft_substr.c ./src/libft/ft_tolower.c \
		./src/libft/ft_toupper.c 																									\


OBJECTS = ${patsubst ${SRCDIR}/%.c, ${OBJDIR}/%.o, ${SRCS}}

all: ${LIBDIR}/${NAME}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@

 ${LIBDIR}/${NAME}: ${OBJECTS}
	@mkdir -p ${LIBDIR}
	@${LIBC} ${LIBDIR}/${NAME} ${OBJECTS}

clean:
	@${RM} ${OBJECTS}

fclean: clean
	@${RM} ${LIBDIR}/${NAME}

re: fclean all

.PHONY: all, clean, fclean, re