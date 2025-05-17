# nombre del ejecutable
TARGET = main

# compilador
CXX = g++
CXXFLAGS = -Wall -std=c++17

# archivos fuente y objeto
SRC = main.cpp implementaciones.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

run: all
	./$(TARGET)

# limpia archivos objeto y el ejecutable
clean:
	rm -f $(TARGET) *.o