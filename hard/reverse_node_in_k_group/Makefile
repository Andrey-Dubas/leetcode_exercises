CC=g++

CFLAGS=-c -Wall -g --std=c++11
LDFLAGS=-lcppunit 

IMPL_SOURCES=
SOURCES=main.cpp $(IMPL_SOURCES)

OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)

EXECUTABLE=app

all: $(SOURCES) $(EXECUTABLE) $(LDFLAGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) --std=c++11 $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(OBJECTS) $(EXECUTABLE)
