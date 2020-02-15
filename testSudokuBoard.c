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
#define EXPERT		1
#define MASTER		2

void test_beginner() {
	char str[MAX_STRING];

	printf("--- Testing Beginner Puzzles ---\n");

	for (int i = 0; i < BIGINNER; i++) {
		snprintf(str, MAX_STRING, "puzzles/Beginner/%d.txt", i);
		//printf("%s\n", str);

		Board b = create_board(str);
		assert(b != NULL);

		// solve_puzzle(b);
		Coords c = create_coords();
		backtrack_solve(b,c);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed (%d)\n", i, c->count);
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		free(c);
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

		// solve_puzzle(b);
		Coords c = create_coords();
		backtrack_solve(b,c);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed (%d)\n", i, c->count);
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		free(c);
		destroy_board(b);
	}
	printf("\033[0m"); // resets text colour
}

void test_medium() {
	char str[MAX_STRING];

	printf("--- Testing Medium Puzzles ---\n");

	for (int i = 0; i < MEDIUM; i++) {
		snprintf(str, MAX_STRING, "puzzles/Medium/%d.txt", i);
		// printf("%s\n", str);

		Board b = create_board(str);
		assert(b != NULL);

		// solve_puzzle(b);
		Coords c = create_coords();
		backtrack_solve(b,c);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed\n", i);
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		free(c);
		destroy_board(b);
	}
	printf("\033[0m"); // resets text colour
}

void test_hard() {
	char str[MAX_STRING];

	printf("--- Testing Hard Puzzles ---\n");

	for (int i = 0; i < HARD; i++) {
		snprintf(str, MAX_STRING, "puzzles/Hard/%d.txt", i);
		// printf("%s\n", str);

		Board b = create_board(str);
		assert(b != NULL);

		// solve_puzzle(b);
		Coords c = create_coords();
		backtrack_solve(b,c);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed (%d)\n", i, c->count);
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		free(c);
		destroy_board(b);
	}
	printf("\033[0m"); // resets text colour
 }

void test_expert() {
	char str[MAX_STRING];

	printf("--- Testing Expert Puzzles ---\n");

	for (int i = 0; i < EXPERT; i++) {
		snprintf(str, MAX_STRING, "puzzles/Expert/%d.txt", i);
		// printf("%s\n", str);

		Board b = create_board(str);
		assert(b != NULL);

		// solve_puzzle(b);
		Coords c = create_coords();
		backtrack_solve(b,c);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed (%d)\n", i, c->count);
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		free(c);
		destroy_board(b);
	}
	printf("\033[0m"); // resets text colour
}

void test_master() {
	char str[MAX_STRING];

	printf("--- Testing Master Puzzles ---\n");

	for (int i = 0; i < MASTER; i++) {
		snprintf(str, MAX_STRING, "puzzles/Master/%d.txt", i);
		// printf("%s\n", str);

		Board b = create_board(str);
		assert(b != NULL);

		// solve_puzzle(b);
		Coords c = create_coords();
		backtrack_solve(b,c);

		if (valid_board(b)) {
			printf("\033[0;32m"); // set output colour to green
			printf("test %d - passed (%d)\n", i, c->count);
		} else {
			printf("\033[0;31m"); // set output colour to red
			printf("test %d - failed (%d/%d)\n", i, count_solved(b), SIZE*SIZE);
		}
		free(c);
		destroy_board(b);
	}
	printf("\033[0m"); // resets text colour
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
		test_medium();
		test_hard();
		test_expert();
		test_master();
	}
	
	return 0;
}
