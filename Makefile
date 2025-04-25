# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Files
MAIN_EXEC = main
TEST_EXEC = test
MAIN_SRC = main.cpp SquareMat.cpp
TEST_SRC = tests.cpp SquareMat.cpp

# Default target: compile main
all: $(MAIN_EXEC)

# Compile main
$(MAIN_EXEC): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXEC) $(MAIN_SRC)

# Run main executable
run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Compile and run tests
test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_SRC)
	./$(TEST_EXEC)

# Run valgrind memory check on main
valgrind: $(MAIN_EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(MAIN_EXEC)

# Clean object files and executables
clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC)
