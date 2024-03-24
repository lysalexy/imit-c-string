CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
LFLAGS = -lcheck -lsubunit -lrt -lpthread -lm
LMACFLAGS = -lcheck 
CHECKLEAKS = valgrind --leak-check=full --track-origins=yes ./test

EXE_NAME = test
LIB_NAME = imit_string.a
GCOV_NAME = imit_string_tests.info
LIB_SRC = $(wildcard lib/*.c)
TEST_SRC = $(wildcard tests/*.c)

LIB_O = $(LIB_SRC:.c=.o)
TEST_O = $(TEST_SRC:.c=.o)

all: clean imit_string.a test gcov_report

all_mac: clean imit_string.a test_for_mac gcov_report_mac

imit_string.a: $(LIB_O)
	ar rc $(LIB_NAME) $(LIB_O)
	ranlib $(LIB_NAME)
	rm -rf lib/*.o

test: $(TEST_O) $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_O) -o $(EXE_NAME) -L. -l:$(LIB_NAME) $(LFLAGS)
	rm -rf $(TEST_O)
	./$(EXE_NAME)
	rm $(EXE_NAME)

test_for_mac: $(TEST_O) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $(EXE_NAME) $(TEST_O) ./$(LIB_NAME) $(LMACFLAGS)
	rm -rf $(TEST_O)
	rm $(LIB_NAME)

gcov_report: clean
	$(CC) $(LIB_SRC) $(TEST_SRC) -o $(EXE_NAME) $(LFLAGS) --coverage 
	./$(EXE_NAME)
	lcov -t "gcov_tests" -o $(GCOV_NAME) -c -d .
	genhtml -o report $(GCOV_NAME)
	rm -rf *.gcno *.gcda *.gcov $(GCOV_NAME)

gcov_report_mac: clean
	$(CC) $(LMACFLAGS) -o $(EXE_NAME) $(LIB_SRC) $(TEST_SRC) --coverage 
	./$(EXE_NAME)
	lcov -t "gcov_tests" -o $(GCOV_NAME) -c -d .
	genhtml -o report $(GCOV_NAME)
	rm -rf *.gcno *.gcda *.gcov $(GCOV_NAME)

clean:
	rm -f $(LIB_NAME) $(EXE_NAME) *.gcno *.gcda *.gcov $(GCOV_NAME)
	rm -rf report/* tests/*.o

style_check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n tests/*.c tests/*.h lib/*.c lib/*.h
	rm -rf .clang-format

style_fix:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i tests/*.c tests/*.h lib/*.c lib/*.h
	rm -rf .clang-format

valgrind:
	$(CHECKLEAKS)

valgrind_2: $(TEST_O) $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_O) -o $(EXE_NAME) -L. -l:$(LIB_NAME) $(LFLAGS)
	rm -rf $(TEST_O)
	$(CHECKLEAKS)

leaks:
	$(CHECKLEAKSMAC)
