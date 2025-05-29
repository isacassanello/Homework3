TARGET = main

CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iheaders

SRCS = sources/main.cpp \
       sources/ConstruirJson.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f sources/*.o $(TARGET)