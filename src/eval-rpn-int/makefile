CC:=gcc
CCFLAGS:=-g -I.
CPP:=g++
CPPFLAGS:=-g -I.

eval_rpn_int_cpp.o: eval_rpn_int.cpp
	$(CC) $(CCFLAGS) -c eval_rpn_int.cpp -o eval_rpn_int_cpp.o

test_eval_rpn_int_cpp.o: test_eval_rpn_int.cpp
	$(CPP) $(CPPFLAGS) -c test_eval_rpn_int.cpp -o test_eval_rpn_int_cpp.o

test_eval_rpn_int: eval_rpn_int_cpp.o test_eval_rpn_int_cpp.o
	$(CPP) $(CCFLAGS) eval_rpn_int_cpp.o test_eval_rpn_int_cpp.o -lm -lgtest -lgtest_main -o test_eval_rpn_int

check: test_eval_rpn_int
	./test_eval_rpn_int

clean:
	rm -rf eval_rpn_int_cpp.o
	rm -rf test_eval_rpn_int_cpp.o
	rm -rf test_eval_rpn_int