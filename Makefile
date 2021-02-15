CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address -std=c++98
NAME = containers

HEADERS = -I iterators -I test_files -I containers

ITERATORS_PATH = iterators/
ITERATORS_FILE = bidirectional_iterator.hpp \
checkers.hpp \
is_const_it.hpp \
random_access_iterator.hpp \
rev_random_access_iterator.hpp \
reverse_bidirectional_iterator.hpp \

TEST_PATH = test_files/
TEST_FILE = tests.hpp \
tests_helpers.hpp \
main.hpp \

CONTAINERS_PATH = containers/
CONTAINERS_FILE = vector/vector.hpp \
queue/queue.hpp \
stack/stack.hpp \

SRC = ${addprefix ${CONTAINERS_PATH}, $(CONTAINERS_FILE)}\
	  ${addprefix ${ITERATORS_PATH}, $(ITERATORS_FILE)}\
	  ${addprefix ${TEST_PATH}, $(TEST_FILE)}
OBJS = ${SRC:%.c=%.o}

all: ${NAME}

$(NAME): ${OBJS}
	@gcc ${CFLAGS} ${HEADERS} ${OBJS} -o ${NAME}
	@echo 
	@echo "\n\033[03m			Creating my containers\033[00m\033[0;32m"
	@echo "──────────────────────────────────────────────────────────────────────────────"
	
	@echo "███████╗████████╗      ██████╗ ██████╗ ███╗   ██╗████████╗ █████╗ ██╗███╗   ██╗███████╗██████╗ ███████╗"
	@echo "██╔════╝╚══██╔══╝     ██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██╔══██╗██║████╗  ██║██╔════╝██╔══██╗██╔════╝"
	@echo "█████╗     ██║        ██║     ██║   ██║██╔██╗ ██║   ██║   ███████║██║██╔██╗ ██║█████╗  ██████╔╝███████╗"
	@echo "██╔══╝     ██║        ██║     ██║   ██║██║╚██╗██║   ██║   ██╔══██║██║██║╚██╗██║██╔══╝  ██╔══██╗╚════██║"
	@echo "██║        ██║███████╗╚██████╗╚██████╔╝██║ ╚████║   ██║   ██║  ██║██║██║ ╚████║███████╗██║  ██║███████║"
	@echo "╚═╝        ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚══════╝\033[00m"
	@echo "                                \033[03mHas been created!\n\033[00m"

%.o : %.c
	@/bin/echo -n [+]
	@gcc $(CFLAGS) -c ${HEADERS} $< -o $@

clean:
	@rm -f ${OBJS} ${BONUS}

fclean: clean
	@rm -f ${NAME}

bonus :

re: clean all