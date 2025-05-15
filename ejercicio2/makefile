# nombre del ejecutable
TARGET = main

# compilador
CXX = g++
CXXFLAGS = -Wall -std=c++11

# archivos fuente y objeto
SRC = main.cpp Figuras.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

run: all
	./$(TARGET)

# limpia archivos objeto y el ejecutable
clean:
	rm -f $(TARGET) *.o