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
    -Wpacked  -Wpadded -Wparentheses  -Wpointer-arith \
    -Wredundant-decls -Wreturn-type \
    -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector \
    -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch  -Wswitch-default \
    -Wswitch-enum -Wtrigraphs  -Wuninitialized \
    -Wunknown-pragmas  -Wunreachable-code -Wunused \
    -Wunused-function  -Wunused-label  -Wunused-parameter \
    -Wunused-value  -Wunused-variable  -Wvariadic-macros \
    -Wvolatile-register-var  -Wwrite-strings

all: Math.o
	$(CXX) $(CFLAGS) -isystem /home/saad/Downloads/Boost/boost_1_53_0 Math.o main.cpp -o main

Math.o: Math.h Math.cpp
	$(CXX) $(CFLAGS) -c Math.h Math.cpp
