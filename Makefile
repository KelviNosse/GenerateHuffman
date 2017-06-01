CC=g++
CFLAGS=-c -Wall
SOURCES=main.cpp Test.cpp Node.h Node.cpp Huffman.h Huffman.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Huffman

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-find . -name '*.o' -exec rm -r {} \;
	-rm -f $(EXECUTABLE)

test:
	$ ./Huffman
