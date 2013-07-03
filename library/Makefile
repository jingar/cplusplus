CXX=g++
CFLAGS=-Wall -Wextra -pedantic -std=c++0x -Wall -Weffc++ -pedantic  \
    -pedantic-errors -Wextra  -Wall -Wcast-align \
    -Wcast-qual  -Wchar-subscripts  -Wcomment -Wconversion \
    -Wdisabled-optimization \
    -Wfloat-equal  -Wformat  -Wformat=2 \
    -Wformat-nonliteral -Wformat-security  \
    -Wformat-y2k \
    -Wimport  -Winit-self  -Winline \
    -Winvalid-pch   \
    -Wunsafe-loop-optimizations  -Wlong-long -Wmissing-braces \
    -Wmissing-field-initializers -Wmissing-format-attribute   \
    -Wmissing-include-dirs -Wmissing-noreturn \
    -Wpacked -Wpadded -Wparentheses  -Wpointer-arith \
    -Wredundant-decls -Wreturn-type \
    -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector \
    -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch  -Wswitch-default \
    -Wswitch-enum -Wtrigraphs -Wuninitialized \
    -Wunknown-pragmas  -Wunreachable-code -Wunused \
    -Wunused-function  -Wunused-label  -Wunused-parameter \
    -Wunused-value  -Wunused-variable  -Wvariadic-macros \
    -Wvolatile-register-var  -Wwrite-strings
LINKING = -c
SRCS = patron.cpp chrono.cpp book.cpp library.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
all: program
program: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o program
patron.o: patron.h patron.cpp
	$(CXX) $(CFLAGS) $(LINKING) patron.cpp

chrono.o: chrono.h chrono.cpp
	$(CXX) $(CFLAGS) $(LINKING) chrono.cpp

book.o: chrono.h book.cpp 
	$(CXX) $(CFLAGS) $(LINKING) book.cpp

library.o: book.h patron.h library.cpp
	$(CXX) $(CFLAGS) $(LINKING) library.cpp

main.o: library.h main.cpp
	$(CXX) $(CFLAGS) $(LINKING) main.cpp

clean:
	\rm -f $(OBJS)
