CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

prefix_count.o: prefix_count.cpp
	$(CC) $(CCFLAGS) -c prefix_count.cpp -o prefix_count.o

test_prefix_count_cpp.o: test_prefix_count_cpp.cpp
	$(CPP) $(CPPFLAGS) -c test_prefix_count_cpp.cpp

test_prefix_count: prefix_count.o test_prefix_count_cpp.o
	$(CPP) $(CCFLAGS) prefix_count.o test_prefix_count_cpp.o -lm -lgtest -lgtest_main -o test_prefix_count

check: test_prefix_count
	./test_prefix_count

clean:
	rm -rf prefix_count.o
	rm -rf test_prefix_count_cpp.o
	rm -rf test_prefix_count