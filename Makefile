CC := gcc

SRC_DIR := ./src
OBJ_DIR := ./obj
HEADER_DIR := ./headers

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))
HEADERS := $(wildcard $(HEADER_DIR)/**/*.h)
CFLAGS := -W -Wall -I$(HEADER_DIR) -O3 -mtune=native -march=native

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(TEST_EXES)
	rm -f test/graph/*
	rm -rf result
	rm -rf html

.DEFAULT_GOAL := main
