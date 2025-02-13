CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

alice_bob_cpp.o: alice_bob.cpp
	$(CC) $(CCFLAGS) -c two_sum.cpp -o alice_bob_cpp.o

test_alice_bob_cpp.o: test_alice_bob_cpp.cpp
	$(CPP) $(CPPFLAGS) -c test_alice_bob_cpp.cpp

test_alice_bob: alice_bob_cpp.o test_alice_bob_cpp.o
	$(CPP) $(CCFLAGS) alice_bob_cpp.o test_alice_bob_cpp.o -lm -lgtest -lgtest_main -o test_alice_bob

check: test_alice_bob
	./test_two_sum

clean:
	rm -rf alice_bob_cpp.o
	rm -rf test_alice_bob_cpp.o
	rm -rf test_alice_bob