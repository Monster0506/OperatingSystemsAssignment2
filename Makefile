CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGETS = banker serialize

.PHONY: all clean

all: $(TARGETS)

banker: banker.cpp
	$(CXX) $(CXXFLAGS) -o banker banker.cpp
serialize: serialize.cpp
	$(CXX) $(CXXFLAGS) -o serialize serialize.cpp

clean:
	rm -f $(TARGETS) *.o 
