# -g for GDB debugger -O3 for max optimization
CXX = g++ -std=c++11 -O3 -g

SOURCES = buttonPress.cc servo.cc
HEADERS = buttonPress.hh
OBJECTS=$(SOURCES:.cc=.o)

LIB_LOCK=liblock.a

all: $(LIB_LOCK)

$(LIB_LOCK): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_LOCK) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_LOCK)
	make -C test clean
