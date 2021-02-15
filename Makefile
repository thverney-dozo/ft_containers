NAME = bin
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address -std=c++98

all: ${NAME}

$(NAME):
	@clang++ $(CFLAGS) ./tests/*.cpp -o $(NAME)
	@echo 
	@echo "\n\033[03m					Creating my containers\033[00m\033[0;32m"
	@echo "───────────────────────────────────────────────────────────────────────────────────────────────────────"
	@echo "███████╗████████╗      ██████╗ ██████╗ ███╗   ██╗████████╗ █████╗ ██╗███╗   ██╗███████╗██████╗ ███████╗"
	@echo "██╔════╝╚══██╔══╝     ██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██╔══██╗██║████╗  ██║██╔════╝██╔══██╗██╔════╝"
	@echo "█████╗     ██║        ██║     ██║   ██║██╔██╗ ██║   ██║   ███████║██║██╔██╗ ██║█████╗  ██████╔╝███████╗"
	@echo "██╔══╝     ██║        ██║     ██║   ██║██║╚██╗██║   ██║   ██╔══██║██║██║╚██╗██║██╔══╝  ██╔══██╗╚════██║"
	@echo "██║        ██║███████╗╚██████╗╚██████╔╝██║ ╚████║   ██║   ██║  ██║██║██║ ╚████║███████╗██║  ██║███████║"
	@echo "╚═╝        ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚══════╝"
	@echo "───────────────────────────────────────────────────────────────────────────────────────────────────────\033[00m"
	@echo "                                \033[03m	   Has been created!\n\033[00m"

clean:
	@rm -f tests/*.o
	@rm -rf *.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all
