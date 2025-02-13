CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

rotate_array_cpp.o: rotate_array.cpp
	$(CC) $(CCFLAGS) -c rotate_array.cpp -o rotate_array_cpp.o

test_rotate_array_cpp.o: test_rotate_array_cpp.cpp
	$(CPP) $(CPPFLAGS) -c test_rotate_array_cpp.cpp

test_rotate: rotate_array_cpp.o test_rotate_array_cpp.o
	$(CPP) $(CCFLAGS) rotate_array_cpp.o test_rotate_array_cpp.o -lm -lgtest -lgtest_main -o test_rotate

check: test_rotate
	./test_rotate

clean:
	rm -rf rotate_array_cpp.o
	rm -rf test_rotate_array_cpp.o
	rm -rf test_rotate