.PHONY: all test gcov gcov_report style gost clean

# UTILITIES
CC = gcc
MK = mkdir -p
RM = rm -rf
OS := $(shell uname)
ifeq ($(OS), Darwin)
	LEAKS = CK_FORK=no leaks --atExit --
	REPORT_OPEN = open
else ifeq ($(OS), Linux)
	LEAKS =
	REPORT_OPEN = xdg-open
endif

# UTILITIES OPTIONS
DEBUG = -DDEBUG
CF = -Wall -Werror -Wextra
STD = -std=c11 -pedantic
ASAN = -g -fsanitize=address
ifeq ($(OS), Darwin)
	TEST_FLAGS = -lcheck
else ifeq ($(OS), Linux)
	TEST_FLAGS = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# FILENAMES
ATTEMPT_DIR = ./attempt_at_writing/

SRC_DIR = ./src/

UI_DIR = $(SRC_DIR)01_ui/
CREDIT_DIR = $(SRC_DIR)04_credit_calculator/
DEPOSIT_DIR = $(SRC_DIR)05_deposit_calculator/

DATA_STRUCT_DIR = $(SRC_DIR)02_data_structs_processing/
EVAL_DIR = $(SRC_DIR)03_evaluations/
SRC = $(wildcard $(DATA_STRUCT_DIR)*.c)
SRC += $(wildcard $(EVAL_DIR)*.c)

BUILD_DIR = ./build/
APP = SmartCalc_v1.app

MAN_TESTS_DIR = ./man_tests/
TESTS_DIR = ./tests/
TESTS_SRC = $(wildcard $(TESTS_DIR)*.c)
TEST_EXE = ./tests_runner

# BUILD
all: clean style test gcov_report install dvi dist

# TESTS
test: clean
	@$(CC) $(CF) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TEST_EXE) $(TEST_FLAGS)
	@$(TEST_EXE)

gcov: gcov_report

gcov_report: clean
	@$(CC) $(CF) $(GCOV_FLAGS) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TEST_EXE) $(TEST_FLAGS)
	@$(TEST_EXE)
	@lcov -t "./gcov" -o report.info --no-external -c -d .
	@genhtml -o report report.info
	@gcovr -r . --html-details -o ./report/coverage_report.html
	@$(REPORT_OPEN) ./report/index.html
	@rm -rf *.gcno *.gcda gcov_test *.info

man_test: clean
#	$(CC) $(ATTEMPT_DIR)*.c $(DEBUG)
#	$(CC) $(MAN_TESTS_DIR)test_structures.c $(SRC)
#	$(CC) $(MAN_TESTS_DIR)test_convert_infix_to_RPN.c $(SRC) $(DEBUG)
	$(CC) $(MAN_TESTS_DIR)test_evaluate_expression.c $(SRC) $(DEBUG)
	$(LEAKS) ./a.out

leaks: clean
	@$(CC) $(CF) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TEST_EXE) $(TEST_FLAGS)
	@$(LEAKS) $(TEST_EXE)

# QT APP
install:
	$(MK) $(BUILD_DIR)
	cd $(BUILD_DIR) && qmake ../$(UI_DIR)SmartCalc_v1.pro && make -j6 && make clean && rm -rf .qmake.stash Makefile

launch:
	open $(BUILD_DIR)$(APP)

uninstall:
	rm -rf $(BUILD_DIR)*

dvi:
	open $(SRC_DIR)readme.html

dist:
	tar -zcvf SmartCalc_v1.tar $(ALL_DIRS) Makefile

app_leaks:
	$(LEAKS) $(BUILD_DIR)$(APP)/Contents/MacOS/SmartCalc_v1

# SERVICES
style:
	clang-format --style=google -n $(SRC_DIR)*.h $(SRC) $(CREDIT_DIR)* $(DEPOSIT_DIR)* $(UI_DIR)*.h $(UI_DIR)*.cpp $(TESTS_SRC)

gost:
	clang-format --style=google -i $(SRC_DIR)*.h $(SRC) $(CREDIT_DIR)* $(DEPOSIT_DIR)* $(UI_DIR)*.h $(UI_DIR)*.cpp $(TESTS_SRC)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(SRC_DIR)*.o
	@$(RM) ./report/
	@$(RM) *.dSYM
	@$(RM) a.out *.tar
	@$(RM) *.gcno *.gcda
	@$(RM) $(TEST_EXE)
