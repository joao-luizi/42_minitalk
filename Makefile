

NAME = minitalk.a
NAME_BONUS = minitalk_bonus.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -g 
LIBC = ar rcs

RM = rm -f
HOME = ./

SRC_DIR		= ./src
OBJ_DIR 	= ./obj
INC_DIR		= ./inc
BIN_DIR		= ./bin
LIB_DIR		= ./lib

LIBFT_DIR 	= ${LIB_DIR}/libft
LIBFT 		= ${LIBFT_DIR}/lib/libft.a

LIB_NAME = ${LIB_DIR}/${NAME}
LIB_NAME_BONUS = ${LIB_DIR}/${NAME_BONUS}

SRCS_COMMON = 		${SRC_DIR}/common/parser.c ${SRC_DIR}/common/custom_atoi.c  ${SRC_DIR}/common/signals.c ${SRC_DIR}/common/server_signals.c \
					${SRC_DIR}/common/client_signals.c

SRCS_CLIENT = 		${SRC_DIR}/client/client.c	
SRCS_SERVER = 		${SRC_DIR}/server/server.c	

SRCS_COMMON_BONUS = ${SRC_DIR}/common/parser_bonus.c ${SRC_DIR}/common/custom_atoi_bonus.c  ${SRC_DIR}/common/signals_bonus.c ${SRC_DIR}/common/server_signals_bonus.c \
					${SRC_DIR}/common/client_signals_bonus.c

SRCS_CLIENT_BONUS = ${SRC_DIR}/client/client_bonus.c	
SRCS_SERVER_BONUS = ${SRC_DIR}/server/server_bonus.c	
		
OBJS = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS_COMMON}}
CLI_OBJS = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS_CLIENT}}
SRV_OBJS = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS_SERVER}}

OBJS_BONUS = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS_COMMON_BONUS}}
CLI_OBJS_BONUS = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS_CLIENT_BONUS}}
SRV_OBJS_BONUS = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS_SERVER_BONUS}}

all: ${LIB_NAME}


${LIB_NAME}: ${LIBFT} ${CLI_OBJS} ${SRV_OBJS} ${OBJS}
	cp ${LIBFT} ${LIB_NAME}
	${LIBC} ${LIB_NAME} ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${SRCS_CLIENT} ${LIB_NAME} ${LIBFT} -o ${BIN_DIR}/client
	${CC} ${CFLAGS} ${SRCS_SERVER} ${LIB_NAME} ${LIBFT} -o ${BIN_DIR}/server 

${LIB_NAME_BONUS}: ${LIBFT} ${CLI_OBJS_BONUS} ${SRV_OBJS_BONUS} ${OBJS_BONUS}
	cp ${LIBFT} ${LIB_NAME_BONUS}
	${LIBC} ${LIB_NAME_BONUS} ${LIBFT} ${OBJS_BONUS}
	${CC} ${CFLAGS} ${SRCS_CLIENT_BONUS} ${LIB_NAME_BONUS} ${LIBFT} -o ${BIN_DIR}/client_bonus
	${CC} ${CFLAGS} ${SRCS_SERVER_BONUS} ${LIB_NAME_BONUS} ${LIBFT} -o ${BIN_DIR}/server_bonus

${LIBFT}: 
	@${MAKE} -C ${LIBFT_DIR}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

bonus: ${LIB_NAME_BONUS}

clean:
	@${MAKE} -C ${LIBFT_DIR} clean
	@${RM} ${OBJS}
	@${RM} ${CLI_OBJS}
	@${RM} ${SRV_OBJS}
	@${RM} ${OBJS_BONUS}
	@${RM} ${CLI_OBJS_BONUS}
	@${RM} ${SRV_OBJS_BONUS}

fclean:	clean
	@${MAKE} -C ${LIBFT_DIR} fclean
	@${RM} ${LIB_NAME}
	@${RM} ${LIB_NAME_BONUS}

re:	fclean all
 







.PHONY: all clean fclean re
