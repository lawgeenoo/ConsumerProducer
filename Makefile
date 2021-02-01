CC = g++
CXXFLAGS := -std=c++0x -lpthread
INC = -Iinc
BIN_DIR = bin
SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))  
EXEC := CP
CLEAN := rm -rf $(OBJ_DIR) $(BIN_DIR) CP

all: CP

CP: $(OBJ_FILES)
	@$(CC) $(CXXFLAGS) -o $@ $(OBJ_FILES) 
	@mv $(EXEC) $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CXXFLAGS) $(INC) -c -o $@ $<
	
.PHONY: clean
clean:
	@$(CLEAN) 
