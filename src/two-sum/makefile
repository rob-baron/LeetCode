CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

two_sum_cpp.o: two_sum.cpp
	$(CC) $(CCFLAGS) -c two_sum.cpp -o two_sum_cpp.o

test_two_sum_cpp.o: test_two_sum_cpp.cpp
	$(CPP) $(CPPFLAGS) -c test_two_sum_cpp.cpp

test_two_sum: two_sum_cpp.o test_two_sum_cpp.o
	$(CPP) $(CCFLAGS) two_sum_cpp.o test_two_sum_cpp.o -lm -lgtest -lgtest_main -o test_two_sum

check: test_two_sum
	./test_two_sum

clean:
	rm -rf two_sum_cpp.o
	rm -rf test_two_sum_cpp.o
	rm -rf test_two_sum