CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

gen_parens.o: gen_parens.cpp
	$(CC) $(CCFLAGS) -c gen_parens.cpp -o gen_parens.o

test_gen_parens_cpp.o: test_gen_parens_cpp.cpp
	$(CPP) $(CPPFLAGS) -c test_gen_parens_cpp.cpp

test_gen_parens: gen_parens.o test_gen_parens_cpp.o
	$(CPP) $(CCFLAGS) gen_parens.o test_gen_parens_cpp.o -lm -lgtest -lgtest_main -o test_gen_parens

check: test_gen_parens
	./test_gen_parens

clean:
	rm -rf gen_parens.o
	rm -rf test_gen_parens_cpp.o
	rm -rf test_gen_parens