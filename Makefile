
# CONFIGURATION PROJET
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin

SRC_DIR   := src
INC_DIR   := include
TEST_DIR  := tests

# SOURCES
APP_SRCS  := $(SRC_DIR)/main.c

# toutes les sources du projet sauf main.c = librairie
LIB_SRCS  := $(filter-out $(APP_SRCS), $(wildcard $(SRC_DIR)/*.c))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)

# OBJETS
APP_OBJS  := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(APP_SRCS))
LIB_OBJS  := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SRCS))
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_SRCS))

OBJS := $(APP_OBJS) $(LIB_OBJS)

# BINAIRES
TARGET    := $(BIN_DIR)/main.exe
TEST_BIN  := $(BIN_DIR)/test.exe

# TOOLCHAIN
CC := clang

CFLAGS_COMMON := -std=c11 -Wall -Wextra -Werror -Wpedantic \
                 -I$(INC_DIR) -MMD -MP

CFLAGS_DEBUG   := $(CFLAGS_COMMON) -g -O0
CFLAGS_RELEASE := $(CFLAGS_COMMON) -O2

BUILD ?= debug

ifeq ($(BUILD),release)
	CFLAGS := $(CFLAGS_RELEASE)
else
	CFLAGS := $(CFLAGS_DEBUG)
endif

# RULES PRINCIPALES
all: build test run

build: $(TARGET)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_BIN)
	./$(TEST_BIN)

# LINKING
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_BIN): $(TEST_OBJS) $(LIB_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# COMPILATION
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# DOSSIERS
$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

# CLEAN
clean:
	rm -rf $(BUILD_DIR)

re: clean all

# DEPENDANCES AUTO
DEPS := $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)
-include $(DEPS)

# PHONY
.PHONY: all build run test clean re
