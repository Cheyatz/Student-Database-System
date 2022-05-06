CC := g++
CCFLAGS := -Iheaders

SRC_DIR := src
OBJ_DIR := obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) # *.o doesn't work on assignment that is why we use wildcard function
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))  # Whitespace matters bae!

a : $(OBJ_FILES)
	@echo '"$(OBJ_FILES)"'
	$(CC) $(CCFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean : 
	rm -rf obj/*.o a
