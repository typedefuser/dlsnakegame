# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11 -I include -I C:/raylib/raylib/src

# Raylib library path
RAYLIB_PATH = C:/raylib/raylib/src

# Source files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Executable name
TARGET =game 

# Linking flags
LDFLAGS = -L$(RAYLIB_PATH) -lraylib -lm -lpthread -lwinmm -lgdi32 

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the application
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
