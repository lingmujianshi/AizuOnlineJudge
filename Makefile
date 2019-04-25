DBG=-g -o0
CXXFLAGS= -std=c++11 -I/usr/local/include/
LDLIBS = -L/usr/local/lib
OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TARGET = main

all:
	clang++ main.cpp -std=c++11 -o main
	./main
	rm main

.PHONY: clean

$(TARGET): $(OBJECTS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

debug: main.cpp
	clang++ main.cpp -std=c++11 -g -o0 -o main
clean:
	$(RM) -R a.* *.dSYM $(OBJECTS) $(TARGET)
# DO NOT DELETE
