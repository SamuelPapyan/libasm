NAME = libasm.a

ASMC = nasm
ASMFLAGS = crs

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
ifeq ($(DEBUG), true)
	CDEBUG = -g
endif

RM = rm
RMFLAGS = -f

SRC_DIR = src
OBJ_DIR = obj

SRC_BONUS_DIR = src_bonus

SRCS = $(wildcard $(SRC_DIR)/*.s)
BONUS_SRCS = $(wildcard $(SRC_BONUS_DIR)/*.s)

vpath %.s $(SRC_DIR) $(SRC_BONUS_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.s=.o)))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS:.s=.o)))


