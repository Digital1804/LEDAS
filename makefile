CC = g++
HEADER = point_circle.h
SRC_MAIN = main.cpp
SRC_LIB = point_circle.cpp

OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_LIB = $(SRC_LIB:.cpp=.o)

EXE = $(SRC_MAIN:.cpp=)

.PHONY: all clean
all: $(EXE_MAIN)

$(EXE_MAIN): $(OBJ_MAIN) $(OBJ_LIB)
	$(CC) -o $@ $(OBJ_MAIN) $(OBJ_LIB)

# Генерация object-файлов из C-файлов
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#g++ main.cpp point_circle.cpp -o distance_calculator