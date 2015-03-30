CC := g++
CXXFLAGS := -std=c++11 -c 
LIBS := -lgtest -lpthread

# Directories
BUILD := build
BIN := bin
INCLUDE := -I include
SOURCE := src
TEST := test

# Source files
SOURCES := $(shell find $(SOURCE) -name '*.cpp')
TESTS := $(shell find $(TEST) -name '*.cpp')

# Object files
SOURCE_OBJECTS := $(patsubst $(SOURCE)/%,$(BUILD)/%,$(SOURCES:.cpp=.o))
TEST_OBJECTS := $(patsubst $(TEST)/%,$(BUILD)/%,$(TESTS:.cpp=.o))

# Binary files
TEST_BINARY := roman_numbers_test
RELEASE_BINARY := roman_numbers

# Targets
TEST_TARGET := test
RELEASE_TARGET := release

# Rule definitions
LINK_RULE = $(CC) -o $(BIN)/$(BINARY) $^ $(LIBS)
COMPILE_RULE = $(CC) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(RELEASE_TARGET): $(SOURCE_OBJECTS)
	$(eval BINARY := $(RELEASE_BINARY))
	@echo "Linking $^..."
	@mkdir -p bin
	$(LINK_RULE)

$(TEST_TARGET): $(TEST_OBJECTS) $(SOURCE_OBJECTS)
	$(eval BINARY := $(TEST_BINARY))
	@echo "Linking $^..."
	@mkdir -p bin
	$(LINK_RULE)
	
test-and-run: $(TEST_TARGET)
	$(BIN)/$(TEST_BINARY)
	
$(BUILD)/%.o: $(SOURCE)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p build
	$(COMPILE_RULE)

$(BUILD)/%.o: $(TEST)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p build
	$(COMPILE_RULE)
	
clean:
	@echo "Removing binaries..."
	rm -r $(BIN)
	@echo "Removing object files..."
	rm -r $(BUILD)
