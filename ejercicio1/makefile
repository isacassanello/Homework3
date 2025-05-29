TARGET = main

CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iheaders

SRC = sources/main.cpp sources/MedicionBase.cpp sources/Posicion.cpp sources/Presion.cpp sources/SaveFlightData.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) sources/*.o