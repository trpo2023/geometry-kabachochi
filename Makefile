APP_NAME = geometry
LIB_NAME = libgeometry
DATA_NAME = data.txt
TEST_NAME = test

CFLAGS = -Wall -Werror -I src -I thirdparty
CPPFLAGS = -MMD
COMP = gcc

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test
THIRDPARTY_DIR = thirdparty

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
DATA_PATH = $(BIN_DIR)/$(DATA_NAME)
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.c)
APP_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

create: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(COMP) $(CFLAGS) -g3 -O0 -o $@ $^ -lm

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(COMP) $(CFLAGS) -g3 -O0 -c -o $@ $< -lm

clean:
	$(RM) $(APP_PATH) $(OBJ_DIR)/$(SRC_DIR)/*/*.[aod]

run:
	./$(APP_PATH) $(DATA_PATH)

test: $(TEST_PATH)

-include $(DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(COMP) $(CFLAGS) $^ -o $@ -lm -MP

runtest:
	./$(TEST_PATH)

.PHONY: clean create run test runtest