# Nombre del ejecutable
TARGET = main

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iheaders

# Archivos fuente
SRCDIR = sources
OBJDIR = obj
OBJS = $(OBJDIR)/main.o $(OBJDIR)/Clase2.o

# Regla por defecto
all: $(TARGET)

# Compilación final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilar cada archivo fuente por separado
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ejecutar el programa
run: all
	./$(TARGET)

# Limpiar archivos generados
clean:
	rm -rf $(OBJDIR) $(TARGET)