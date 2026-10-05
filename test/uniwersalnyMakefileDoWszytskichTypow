CXX = clang++
# Szuka plików nagłówkowych (.h/.hpp) w katalogu głównym oraz w include/
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g -fsanitize=address -I. -Iinclude

# Nazwa pliku wykonywalnego i katalogu wyjściowego
TARGET_NAME = program
OBJ_DIR = build
TARGET = $(OBJ_DIR)/$(TARGET_NAME)

# Automatyczne wyszukiwanie wszystkich plików .cpp (z pominięciem samego katalogu build)
SRCS = $(shell find . -maxdepth 3 -type f -name "*.cpp" ! -path "./$(OBJ_DIR)/*")

# Zamiana ścieżki ścieżka/plik.cpp na build/ścieżka/plik.o
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

# Linkowanie pliku wykonywalnego bezpośrednio w katalogu build/
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Kompilacja poszczególnych plików .cpp do plików obiektowych .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Uruchamianie z opcjonalnymi argumentami: make run ARGS="dane.txt wyjscie.txt"
run: $(TARGET)
	./$(TARGET) $(ARGS)

# Czyszczenie: usuwa cały katalog build/
clean:
	rm -rf $(OBJ_DIR)

.PHONY: all run clean
