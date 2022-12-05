.PHONY: all
all: hello ut

hello: HelloWorld.cpp
	g++ HelloWorld.cpp -o HelloWorld

ut: ut_main.cpp
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all