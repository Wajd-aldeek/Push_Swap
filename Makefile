CC=cc
CFLAGS=-Wall -Wextra -Werror -Iinclude
NAME=push_swap

SRCS= \
	src/ops/pa.c \
	src/ops/pb.c \
	src/ops/rr.c \
	src/ops/rrr.c \
	src/ops/ss.c \
	src/main/main.c \
	src/error/error.c \
	src/parsing/input_validation.c \
	src/parsing/flags.c \
	src/stack/stack_build.c \
	src/stack/stack_free.c \
	src/algorithms/simple/bubble_sort.c \
	src/algorithms/simple/sort_small.c \
	src/algorithms/medium/chunks_algo.c \
	src/algorithms/medium/chunks_utils.c \
	src/algorithms/complex/radix_sort.c \
	src/metrics/disorder.c \
	src/bench/bench_utils.c \
	src/bench/bench_print.c \
	src/bench/bench_count.c \
	src/utils/ft_split.c \
	src/utils/ft_atoi.c\
	src/utils/check_duplicate.c\
	src/utils/make_indexing.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
