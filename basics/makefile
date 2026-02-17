# Compiler and flags
CXX = g++
CXXFLAGS = -O3 -std=c++20 -Wall -Wextra

# Default target
all:
	@echo "Usage: make <name> to compile <name>.cpp into executable <name>"
	@echo "Example: make array"

# Generic rule: build executable from cpp file
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Compiled $< -> $@"

# Clean all executables in current folder
clean:
	rm -f $(patsubst %.cpp,%,$(wildcard *.cpp))
	@echo "Cleaned all executables"

