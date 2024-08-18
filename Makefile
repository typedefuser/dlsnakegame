# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11 -I include -I C:/raylib/raylib/src -I src

# Raylib library path
RAYLIB_PATH = C:/raylib/raylib/src

# Source files
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,obj/%.o,$(SRC))  # Save .o files in the obj directory

# Executable name
TARGET =game 

# Linking flags
LDFLAGS = -L$(RAYLIB_PATH) -lraylib -lm -lpthread -lwinmm -lgdi32 

# Default target
all: $(OBJ) $(TARGET)  # Ensure .o files are built before the target

# Build the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files to object files
obj/%.o: src/%.cpp | obj  # Ensure obj directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Clean up build files
clean:
	rm -f obj/*.o $(TARGET)  # Update clean command to remove .o files from the obj directory

# Run the application
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run obj