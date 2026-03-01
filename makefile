CC = gcc
CFLAGS = -Wall -W -std=c11
TARGET = nfl_score
SRC = nfl_score.c
TARGET2 = temp_convert
SRC2 = temp_convert.c

all: $(TARGET) $(TARGET2)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

$(TARGET2): $(SRC2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SRC2)

clean:
	rm -f $(TARGET) $(TARGET2)