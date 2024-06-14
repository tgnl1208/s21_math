COMPILE_FLAGS = -Wall -Wextra -Werror -Wpedantic -std=c11
MAXIMUM_PAIN = -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: s21_math.a test gcov_report

%.o: %.c
	gcc $(COMPILE_FLAGS) -c $< -o $@

s21_math.a: $(OBJ)
	ar rcs $@ $^
	rm -f $(OBJ)

test: s21_math.a
	gcc $(COMPILE_FLAGS) tests/unit_tests.c s21_math.a -o tests/unit_tests -lcheck -lrt -lm -lsubunit
	./tests/unit_tests
	# valgrind --tool=memcheck --leak-check=yes ./tests/unit_tests

gcov_report: $(OBJ)
	gcc $(GCOVFLAGS) tests/unit_tests.c $(SRC) -o report.out -lcheck -lrt -lm -lsubunit
	./report.out
	gcov -f *.gcda
	lcov -c -d . -o Coverage_Report.info
	genhtml Coverage_Report.info -o report
	rm -f *.gcno *.gcda *.info report.out *.gcov
	rm -f $(OBJ)
	open ./report/index.html

style:
	clang-format -i *.c *.h tests/*.c
	clang-format -n *.c *.h tests/*.c

rebuild: clean all

clean: 
	rm -f *.o *.a tests/unit_tests *.gcno *.gcda tests/*.gcno tests/*.gcda *.out *.gcov
	rm -rf report
