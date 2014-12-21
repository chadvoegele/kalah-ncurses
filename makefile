SHELL=/usr/bin/bash
CXX=g++
CC=g++
CPPFLAGS=-g -Wall -std=c++11
INC=-Isrc
CPP_FILES= $(wildcard src/*.cpp)
TEST_CPP_FILES= $(wildcard testsrc/*.cpp)
OBJ_FILES= $(addprefix bin/,$(notdir $(CPP_FILES:.cpp=.o)))
TEST_OBJ_FILES= $(addprefix bin/,$(notdir $(TEST_CPP_FILES:.cpp=.o)))
LIBS=-lncurses
TEST_LIBS=-lboost_unit_test_framework -lncurses

main: $(OBJ_FILES)
	$(CXX) $(CPPFLAGS) $(INC) $(LIBS) -o bin/$@ $^

test: $(subst bin/main.o,,$(OBJ_FILES)) $(TEST_OBJ_FILES)
	$(CXX) $(CPPFLAGS) $(INC) $(TEST_LIBS) -o bin/$@ $^

bin/%.o: src/%.cpp
	@mkdir -p bin
	$(CXX) $(CPPFLAGS) $(INC) -c -o $@ $<

bin/%.o: testsrc/%.cpp
	@mkdir -p bin
	$(CXX) $(CPPFLAGS) $(INC) -c -o $@ $<

clean:
	@if test -d bin; then rm -r bin; fi

