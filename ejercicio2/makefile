# Nombre del ejecutable
TARGET = programa

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iheaders

# Archivos fuente
SRCS = sources/main.cpp \
       sources/Punto.cpp \
       sources/Circulo.cpp \
       sources/Elipse.cpp \
       sources/Rectangulo.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Limpieza
clean:
	rm -f sources/*.o $(TARGET)