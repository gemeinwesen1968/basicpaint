# Compiler and flags
CXX := g++
CXXFLAGS := -I./include -L./lib -g
LDFLAGS := -lraylib -lopengl32 -lgdi32 -lwinmm

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
LIB_DIR := lib

# Source files and output
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
TARGET := basic_paint.exe

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Compile each .cpp file into an object file in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
