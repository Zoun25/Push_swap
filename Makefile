########
#COLORS#
########
GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
RESET = \033[0m

#######
#LIBFT#
#######
LIBFT_LIB = libft/libft.a
LIBFT_DIR = libft


#######
#FLAGS#
#######
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

#########
#PROJECT#
#########
NAME = push_swap

SRCS_DIR = ./srcs/
SRCS = 


######
#OBJS#
######
OBJS_DIR = ./objs/
OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}

###################
#COMPILE_AND_PHONY#
###################
${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@printf "${CLEAR}${RESET}${GREEN}»${NAME}: ${PURPLE}Building... 🏗️ $<${RESET}\n" ${notdir $<}
	@cc ${CFLAGS} -I${SRCS_DIR} -c $< -o $@

$(NAME): ${LIBFT_LIB} $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)
	@printf "${CLEAR}${RESET}────────────────────────────────────────────────────\n$(GREEN)»$(NAME): $(RESET)$(PURPLE)Built!🧱\n$(RESET)"
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
$(OBJS):		| $(OBJS_DIR)
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) -s

clean:
	@${RM} ${OBJS_DIR}
	@echo "${RED}${NAME}: ${RESET}${PURPLE}Objects Removed!🧹${RESET}"
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@${RM} ${NAME}
	@echo "${RED}${NAME}: ${RESET}${PURPLE}All Removed!🧹${RESET}"
	@${RM} ${LIBFT_LIB}
	@echo "${RED}libft: ${RESET}${PURPLE}All Removed!🧹${RESET}"

all: $(NAME)

re: fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re