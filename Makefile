# Makefile - Thomas Cholak
CC = g++
CFLAGS = -g -std=c++11
SOURCES = P1.cpp scanner.cpp  # Add scanner.cpp to the sources
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = P1

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
        $(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: all clean
