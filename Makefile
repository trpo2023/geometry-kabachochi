APP_NAME = geometry
LIB_NAME = libgeometry
DATA_NAME = data.txt

CFLAGS = -Wall -Werror -I src
CPPFLAGS = -MMD
COMP = gcc

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
DATA_PATH = $(BIN_DIR)/$(DATA_NAME)

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.c)
APP_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

create: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(COMP) $(CFLAGS) -o $@ $^ 

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(COMP) $(CFLAGS) -c -o $@ $< 

clean:
	$(RM) $(APP_PATH) $(OBJ_DIR)/$(SRC_DIR)/*/*.[aod]

run:
	./$(APP_PATH) $(DATA_PATH)

.PHONY: clean create run