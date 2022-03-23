CC=gcc
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage

all: tests
tests.o: tests.c
	${CC} -c tests.c -o tests.o ${CFLAGS}
stack.o: graph.c
	${CC} -c graph.c -o graph.o ${CFLAGS}
tests: tests.o graph.o
	${CC} graph.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../graph.tgz ../graph
