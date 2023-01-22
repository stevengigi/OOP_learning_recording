cc =g++
src = $(shell find ./src/-name "*.cpp")
cflag= -std=c++11 -lgtest -lpthread  -Wfatal-errors
out = bin/ut_all

.PHONY: all
all: hello ut

hello: src/HelloWorld.cpp
	$(cc)  $(src)  -o bin/HelloWorld

ut: test/ut_main.cpp
	$(cc)  $(source) test/ut_main.cpp   -o $(out) $(cflag)

.PHONY: clean
clean:
	rm -f bin/*
