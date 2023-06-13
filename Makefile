CC=g++
CFLAGS=-std=c++17


TARGET=program
BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
ENTITIES_DIR = ./entities

all: $(TARGET)

searchMachine.o: $(INCLUDE_DIR)/searchMachine.h $(SRC_DIR)/$(ENTITIES_DIR)/searchMachine.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(ENTITIES_DIR)/searchMachine.cpp

main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/searchMachine.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp

$(TARGET): main.o searchMachine.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) main.o

clean:
	rm -f *.o $(BUILD_DIR)/$(TARGET)

