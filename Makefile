CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGETS = banker

.PHONY: all clean

all: $(TARGETS)

banker: banker.cpp
	$(CXX) $(CXXFLAGS) -o banker banker.cpp

clean:
	rm -f $(TARGETS) *.o 
