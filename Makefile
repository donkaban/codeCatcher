CXX=clang++

COMPILE_PARAMS=-c -Wall -Wextra -std=c++11 -I./include -I/usr/local/include -O3 -pedantic -stdlib=libc++
LINK_PARAMS=-L/usr/local/lib -lopencv_core -lopencv_highgui -stdlib=libc++

TARGET=./test
SOURCES=main.cpp cvImpl.cpp

OBJECTS=$(SOURCES:.cpp=.o)
.SUFFIXES: .cpp .o

all: $(SOURCES) $(TARGET) Makefile

$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) $(LINK_PARAMS) -o $@
	rm -f $(OBJECTS)
	
.cpp.o: $(SOURCES) 
	$(CXX) $(COMPILE_PARAMS) -c -o $@ $<

clean:
	rm -f $(TARGET)
	rm -f $(OBJECTS)