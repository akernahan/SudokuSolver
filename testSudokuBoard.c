#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "sudokuSolver.h"

#define MAX_STRING	128

#define BIGINNER	6
#define EASY		5
#define MEDIUM		0
#define HARD		0
#define EXPERT		0
#define MASTER		0

void test_beginner() {
	char str[MAX_STRING];

	printf("--- Testing Beginner Puzzles ---\n");

	for (int i = 0; i < BIGINNER; i++) {
		snprintf(str, MAX_STRING, "puzzles/Beginner/%d.txt", i);
		//printf("%s\n", str);

		Board b = create_board(str);
		assert(b != NULL);

		solve_puzzle(b);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed\n", i);
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		destroy_board(b);
	}
	printf("\033[0m"); // resets text colour
}

void test_easy() {
	char str[MAX_STRING];

	printf("--- Testing Easy Puzzles ---\n");

	for (int i = 0; i < EASY; i++) {
		snprintf(str, MAX_STRING, "puzzles/Easy/%d.txt", i);
		// printf("%s\n", str);

		Board b = create_board(str);
		assert(b != NULL);

		solve_puzzle(b);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed\n");
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		destroy_board(b);
	}
	printf("\033[0m"); // resets text colour
}

void test_medium() {

}

void test_hard() {

 }

void test_expert() {

}

void test_master() {

}

void test_one() {
	Board b = create_board("puzzles/Master/0.txt");
	assert(b != NULL);
	Coords c = create_coords();

	print_board(b);
	backtrack_solve(b,c);
	print_board(b);

	destroy_board(b);
	free(c);
}

int main(int argc, char *argv[]) {
	
	if (argc > 1) {
		test_one();
	}
	else {
		test_beginner();
		test_easy();
	}
	
	return 0;
}
