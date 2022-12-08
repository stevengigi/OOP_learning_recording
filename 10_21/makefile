.PHONY: all
all: hello ut

hello: src/HelloWorld.cpp
	g++ src/MathVector.cpp src/HelloWorld.cpp src/Circle.cpp src/Polygon.cpp -o bin/HelloWorld

ut: test/ut_main.cpp
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp  src/Triangle.cpp src/MathVector.cpp src/Circle.cpp src/Polygon.cpp -o bin/ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm -f bin/*
