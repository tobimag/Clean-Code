CC := g++
CXXFLAGS := -std=c++11 -c 
LIB := -lgtest -lpthread

# Directories
BUILD := build
BIN := bin
INCLUDE := -I include
SOURCE := src
TEST := test

#Files
SOURCES := $(shell find $(SOURCE) -name '*.cpp')
SOURCE_OBJECTS := $(patsubst $(SOURCE)/%,$(BUILD)/%,$(SOURCES:.cpp=.o))
TESTS := $(shell find $(TEST) -name '*.cpp')
TEST_OBJECTS := $(patsubst $(TEST)/%,$(BUILD)/%,$(TESTS:.cpp=.o))

release: $(SOURCE_OBJECTS)
	@echo "Linking $^..."
	@mkdir -p bin
	$(CC) -o $(BIN)/roman_numbers $^ $(LIB)

test: $(TEST_OBJECTS) $(SOURCE_OBJECTS)
	@echo "Linking $^..."
	@mkdir -p bin
	$(CC) -o $(BIN)/roman_numbers_test $^ $(LIB)

$(BUILD)/%.o: $(SOURCE)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p build
	$(CC) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(BUILD)/%.o: $(TEST)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p build
	$(CC) $(CXXFLAGS) $(INCLUDE) $< -o $@
	
clean:
	@echo "Removing binaries..."
	rm -r $(BIN)
	@echo "Removing object files..."
	rm -r $(BUILD)
