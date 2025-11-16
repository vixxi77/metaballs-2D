CC = gcc

LDFLAGS = -lraylib -lm

SRC = metaballs.c

TARGET = metaballs

all:
	$(CC) $(SRC) $(LDFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)
