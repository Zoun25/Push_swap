########
#COLORS#
########
GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
RESET = \033[0m
CLEAR = \r\033[K

#######
#FLAGS#
#######
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs

#######
#FILES#
#######
NAME = libft.a
SRCS_DIR = ./srcs/
SRCS = libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_strlen.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_memcmp.c \
		libft/ft_strnstr.c \
		libft/ft_memchr.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_abs.c \
		libft/ft_lstnew.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstsize.c \
		libft/ft_lstlast.c \
		libft/ft_lst_init.c \
		libft/ft_lstfree_cont.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_hex.c \
		ft_printf/ft_ptr.c \
		ft_printf/ft_stringnum.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

######
#OBJS#
######
OBJS_DIR = ./objs/
OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}

###################
#COMPILE_AND_PHONY#
###################
${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@printf "${CLEAR}${RESET}${GREEN}»${NAME}: ${PURPLE}Compiling your Library...🗃️ $<${RESET}" ${notdir $<}
	@${CC} ${CFLAGS} -I${SRCS_DIR} -c $< -o $@

$(NAME): ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@printf "${CLEAR}${RESET}${GREEN}»${NAME}: ${RESET}${PURPLE}Compiled!✔️${RESET}\n────────────────────────────────────────────────────\n"

${OBJS}:		| ${OBJS_DIR}

${OBJS_DIR}:
	@mkdir ${OBJS_DIR}
	@mkdir ${OBJS_DIR}libft
	@mkdir ${OBJS_DIR}ft_printf
	@mkdir ${OBJS_DIR}get_next_line

clean:
	@${RM} ${OBJS_DIR}
	@echo "${RED}libft: ${RESET}${PURPLE}Objects Removed!🧹${RESET}"

fclean: clean
	@${RM} ${NAME}
	@echo "${RED}libft: ${RESET}${PURPLE}All Removed!🧹${RESET}"

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re