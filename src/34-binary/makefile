CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

pseudo_bs_cpp.o: pseudo_bs.cpp
	$(CC) $(CCFLAGS) -c pseudo_bs.cpp -o pseudo_bs_cpp.o

test_pseudo_bs_cpp.o: test_pseudo_bs_cpp.cpp
	$(CPP) $(CPPFLAGS) -c test_pseudo_bs_cpp.cpp

test_pseudo_bs: pseudo_bs_cpp.o test_pseudo_bs_cpp.o
	$(CPP) $(CCFLAGS) pseudo_bs_cpp.o test_pseudo_bs_cpp.o -lm -lgtest -lgtest_main -o test_pseudo_bs

check: test_pseudo_bs
	./test_pseudo_bs

clean:
	rm -rf pseudo_bs_cpp.o
	rm -rf test_pseudo_bs_cpp.o
	rm -rf test_pseudo_bs