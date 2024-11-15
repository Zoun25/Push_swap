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
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#########
#PROJECT#
#########
NAME = push_swap
NAME_BONUS = checker

SRCS_DIR = ./srcs/
SRCS_DIR_BONUS= ./srcs_bonus/
SRCS =
SRCS_BONUS =

######
#OBJS#
######
OBJS_DIR = ./objs/
OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}
OBJS_BONUS = ${addprefix ${OBJS_DIR}bonus/, ${SRCS_BONUS:.c=.o}}

###################
#COMPILE_AND_PHONY#
###################
${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@echo "${GREEN}${NAME}: ${PURPLE}Building...🏗️ $<${RESET}"
	@cc ${CFLAGS} -I${SRCS_DIR} -c $< -o $@

$(NAME): ${LIBFT_LIB} $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)
	@echo "────────────────────────\n$(GREEN)$(NAME): $(RESET)$(PURPLE)Built!🧱$(RESET)"

$(NAME_BONUS): ${LIBFT_LIB} $(OBJS_BONUS)
	@cc $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBFT_LIB)
	@echo "────────────────────────\n$(GREEN)$(NAME_BONUS): $(RESET)$(PURPLE)Bonus Built!🧱$(RESET)"

$(LIBFT_DIR):
	@make -C $(LIBFT_DIR)
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@mkdir $(OBJS_DIR)/bonus
$(OBJS):		| $(OBJS_DIR)
$(OBJS_BONUS):		| $(OBJS_DIR)
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

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

bonus: $(NAME_BONUS)

re: fclean all

.SILENT: all clean fclean re bonus
.PHONY: all clean fclean re bonus