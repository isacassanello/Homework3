# nombre del ejecutable
TARGET = main

# compilador
CXX = g++
CXXFLAGS = -Wall -std=c++17

# archivos fuente
SRCS = main.cpp Clases.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ejecutar el programa (compila si es necesario)
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)


