#!make -f

demo: TreeDemo.o Tree.o
	clang++-6.0 -std=c++17 $^ -o demo

test: TreeTest.o Tree.o
	clang++-6.0 -std=c++17 $^ -o test

Tree1.o: Tree.cpp
	clang++-6.0 -std=c++17 --compile $< -o Tree1

TreeTest.o: badkan.hpp Tree.hpp

TreeDemo.o: Tree.hpp

clean:
	rm -f *.o demo test
