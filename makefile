CC := emcc
BIN_DIR := .
BUILD_DIR := build
SRC_EXT := cpp
CFLAGS := -g -Wall -Werror -s ASSERTIONS=2 --preload-file src/shaders
LIB :=
INC := -I src

SRC_DIR := src
BUILD_DIR := $(BUILD_DIR)
CODE_TARGET := $(BIN_DIR)/emgl.js
DATA_TARGET := $(BIN_DIR)/emgl.data
TEST_TARGET := $(BIN_DIR)/test.js
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
CODE_OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))

#Compile to objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(shell echo $@ | sed -e 's/\/[^\/]*\.o//g')
	@echo " Compile Code: $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

#Link binary file
$(CODE_TARGET): $(CODE_OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo " Link Code: $(CC) $^ -o $(CODE_TARGET) $(LIB)"; $(CC) $^ -o $(CODE_TARGET) $(CFLAGS) $(LIB)

#Link test file
$(TEST_TARGET): $(CODE_OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo " Link Test: $(CC) $^ -o $(TEST_TARGET) $(LIB)"; $(CC) $^ -o $(TEST_TARGET) $(LIB)

test: CFLAGS = -D RUN_TESTS
test: CODE_TARGET = $(TEST_TARGET)
test: $(TEST_TARGET)

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r ./$(BUILD_DIR)"; $(RM) -r ./$(BUILD_DIR)
	@echo " $(RM) ./$(CODE_TARGET) ./$(DATA_TARGET) ./$(TEST_TARGET)"; $(RM) ./$(CODE_TARGET) ./$(DATA_TARGET) ./$(TEST_TARGET)


.PHONY: clean
.PHONY: test
