#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "sudokuSolver.h"
//#inlcude "sudoku.h"
//#include "Queue.h"

// add starting values to queue
void init_queue(Queue q, Board b) {
	assert(b != NULL);
	assert(q != NULL);
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (b->board[i][j].value) { // != 0
				add_queue(q, create_node(&b->board[i][j]));
			}
		}
	}
}

void remove_possible(Board b, Node *n) {
	assert(b != NULL);
	assert(n != NULL);
	
	remove_possible_row(b, n->c->value, n->c->row);
	remove_possible_column(b, n->c->value, n->c->column);
	remove_possible_box(b,n);
	
	
}

void remove_possible_row(Board b, int v, int row) {
	// maybe check if it has been solved already, but it should not matter
	for (int j = 0; j < SIZE; j++) {
		b->board[row][j].possible[v-1] = FALSE;
	}
}

void remove_possible_column(Board b, int v, int column) {
	for (int i = 0; i < SIZE; i++) {
		b->board[i][column].possible[v-1] = FALSE;
	}
}

void remove_possible_box(Board b, Node *n) {
	int box = get_box(n->c->row, n->c->column);
	for (int i = 0; i < BOX_SIZE; i++) {
		int r = box_row(i,box);
		for (int j = 0; j < BOX_SIZE; j++) {
			int c = box_column(j,box);
			b->board[r][c].possible[n->c->value-1] = FALSE;
		}
		
	}
}

// checks if each cell is solved, finds adds newly solved cells and adds them to the queue
void fill_board(Board b, Queue q) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (b->board[i][j].value == 0) {
				add_solution(q, &b->board[i][j]);
			}
		}
	}
}

// checks if only 1 possible value, then adds that to the queue
void add_solution(Queue q, Cell *c) {
	// already solved
	if (c->value > 0) {
		return;
	}
	
	int counter = 0;
	int v = 0; // possible value
	for (int i = 0; i < SIZE; i++) {
		if (c->possible[i]) {
			counter++;
			v = i+1;
		}
	}
	if (counter == 1) {
		c->value = v;
		add_queue(q,create_node(c));
		return;
	}
	
	if (counter == 0) {
		printf("--- FAIL, WRONG, BUG!!!! ---\n");
	}
	
}

// has a bug, still but okay
void solve_puzzle(Board b) {
	Queue q = new_queue();
	init_queue(q,b);

	while (queue_empty(q)) {
		Node *n = leave_queue(q);
		remove_possible(b, n);
		destroy_node(n);
		
		if (queue_empty(q)) {
			fill_board(b,q);
		}
	}

	// free memory
	destroy_queue(q);

	return;
}
 /*
	Backtrack Algorithm to solve
 */
int backtrack_solve(Board b, Coords c) {

	// stores local row and column co-ordinates
	int row = -1;
	int col = -1;

	// finds unsolved place, if no unsolved then puzzle is solved
	if (!find_empty(b,c)) {
		return TRUE;
	}
	row = c->row;
	col = c->column;

	// consider digits 1-9
	for (int n = 1; n < SIZE+1; n++) {
		
		// possible correct value
		if (is_safe(b, row, col, n)) {
			b->board[row][col].value = n;

			if (backtrack_solve(b,c)) {
				return TRUE; // puzzles completed
			}

			// reset value
			b->board[row][col].value = 0;
		}
	}

	return FALSE;
}

// returns False if there are no values left to find
int find_empty(Board b, Coords c) {
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (b->board[i][j].value == 0) {
				c->row = i;
				c->column = j;
				return TRUE;
			}
		}
	}
	
	return FALSE;
}

int is_safe(Board b, int row, int col, int n) {
	if (!safe_row(b, row, n)) {
		return FALSE;
	}
	if (!safe_col(b, col, n)) {
		return FALSE;
	}
	if (!safe_box(b, get_box(row,col), n)) {
		return FALSE;
	}
	return TRUE;
}

int safe_row(Board b, int row, int n) {
	
	for (int i = 0; i < SIZE; i++) {
		if (b->board[row][i].value == n) {
			return FALSE;
		}
	}
	return TRUE;
}

int safe_col(Board b, int col, int n) {
	for (int i = 0; i < SIZE; i++) {
		if (b->board[i][col].value == n) {
			return FALSE;
		}
	}
	return TRUE;
}

int safe_box(Board b, int box, int n) {
	for (int i = 0; i < BOX_SIZE; i++) {
		for (int j = 0; j < BOX_SIZE; j++) {
			if (b->board[box_row(i,box)][box_column(j,box)].value == n) {
				return FALSE;
			}
		}
	}
	return TRUE;
}

Coords create_coords() {
	Coords new = malloc(sizeof(struct board_pos));
	assert(new != NULL);

	new->row = -1;
	new->column = -1;

	return new;
}
