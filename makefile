CC = gcc
CFLAGS = -Wall -W -std=c11
TARGET = nfl_score
SRC = nfl_score.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)