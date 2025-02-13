CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

pow.o: pow.cpp
	$(CC) $(CCFLAGS) -c pow.cpp -o pow.o

test_pow_cpp.o: test_pow_cpp.cpp
	$(CPP) $(CPPFLAGS) -c test_pow_cpp.cpp

test_pow: pow.o test_pow_cpp.o
	$(CPP) $(CCFLAGS) pow.o test_pow_cpp.o -lm -lgtest -lgtest_main -o test_pow

check: test_pow
	./test_pow

clean:
	rm -rf pow.o
	rm -rf test_pow_cpp.o
	rm -rf test_pow