CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -I/opt/homebrew/include -I/opt/homebrew/include/SDL2
LDFLAGS = -L/opt/homebrew/lib -lSDL2

SRC = src/main.cpp src/Chip8.cpp src/Platform.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = chip8

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
