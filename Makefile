CXX=clang++

C_FLAGS=-c -Wall -Wextra -std=c++11 -I/usr/local/include -O3 -pedantic -stdlib=libc++
L_FLAGS=-L/usr/local/lib -lopencv_core -lopencv_highgui -stdlib=libc++

TARGET=./test
SOURCES=test.cpp 
HEADERS=common.h camera.h 

OBJECTS=$(SOURCES:.cpp=.o)
.SUFFIXES: .cpp .o


all: $(SOURCES) $(HEADERS) $(TARGET) Makefile

$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) $(L_FLAGS) -o $@
	
.cpp.o: $(SOURCES) 
	$(CXX) $(C_FLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET)
	rm -f $(OBJECTS)