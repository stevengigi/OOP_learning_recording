cc = g++
source = $(shell find ./src/ -type f \( -iname "*.cpp" ! -iname "HelloWorld*" \))
cflags = -lgtest -lpthread -std=c++11 -Wfatal-errors
out = bin/ut_all

.PHONY: all
all: hello ut

hello: src/HelloWorld.cpp
	$(cc) $(source) src/HelloWorld.cpp -o bin/HelloWorld

ut: test/ut_main.cpp
	$(cc) $(source) test/ut_main.cpp -o $(out) $(cflags)

.PHONY: clean
clean:
	rm -f bin/*