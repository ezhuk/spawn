# Copyright (c) 2014 Eugene Zhuk.
# Use of this source code is governed by the MIT license that can be found
# in the LICENSE file.

CXX=g++
CXXFLAGS=-m64 -O2 -std=c++11 -Wall -Wextra
INCPATH=-I/usr/include -I./include
LIBS=

LIB=libspawn.a
OBJ=src/spawn.o

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@

.PHONY: all
all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

.PHONY: clean
clean:
	/bin/rm -rf $(LIB) $(OBJ)
