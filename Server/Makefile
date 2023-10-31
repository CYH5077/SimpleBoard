TARGET = test.out
OBJECT = main.o print.o resource/cpu.o resource/memory.o resource/network.o
CC = gcc
CFLAGS = -W -Wall -g -ggdb
FLAGS = -pthread

all : $(TARGET)

$(TARGET) : $(OBJECT)
	$(CC) -o $@ $^ $(FLAGS)

clean : 
	rm $(TARGET) $(OBJECT)
