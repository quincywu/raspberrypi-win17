CXX = g++ -std=c++11 -O3
LIBS = -llock
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc buttonPress_test.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../liblock.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
