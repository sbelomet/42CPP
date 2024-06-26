# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 10:58:20 by sbelomet          #+#    #+#              #
#    Updated: 2024/06/26 12:57:06 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -fsanitize=address -g3

# Variables

NAME		=	bureaucrat3
OBJ_DIR		=	objs/
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
LEAKS		=	leaks --atExit -- 

# Colors

RED 		=	\033[1;91m
YELLOW		=	\033[1;93m
GREEN		=	\033[1;92m
BLUE		=	\033[1;94m
PURPLE		=	\033[1;95m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
MAGENTA		=	\033[0;95m
CYAN		=	\033[1;96m
WHITE		=	\033[0;97m
RAINBOW		=	$(RED)-$(YELLOW)-$(GREEN)-$(CYAN)-$(BLUE)-$(PURPLE)-

# Sources

FILES		=	main AForm Bureaucrat ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm

SRC			=	$(addsuffix .cpp, $(FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# Commands

all:			$(OBJ_DIR) $(NAME)

$(NAME):		$(OBJ)
					@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@echo ""
					@echo "$(GREEN)$(NAME) est compilé !$(DEF_COLOR)🥶🥶🥶"
					@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

$(OBJ_DIR)%.o:	%.cpp	
					@echo "$(YELLOW)$< est dans le four...$(DEF_COLOR)🥵🥵🥵"
					@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
					@echo "$(BLUE)à la poubelle les .o$(DEF_COLOR)🤓🤓🤓"

fclean:			clean
					@rm -rf $(NAME)
					@echo "$(CYAN)à la poubelle l'exec$(DEF_COLOR)🤤🤤🤤"

re:				fclean all

run:			re
					valgrind ./$(NAME)

.PHONY:			all clean fclean re run
