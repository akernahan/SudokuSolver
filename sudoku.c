#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "sudoku.h"

Cell create_cell(int val, int x, int y) {
	Cell new;
	
	new.value = val;
	new.row = x;
	new.column = y;
	
	for (int i = 0; i < SIZE; i++)
		new.possible[i] = TRUE;
	
	return new;
}

int get_box(int row, int column) {
	return row/BOX_SIZE * BOX_SIZE + column/BOX_SIZE;
}

int box_row(int i, int box) {
	return box/BOX_SIZE * BOX_SIZE + i;
}

int box_column(int j, int box) {
	return (box%BOX_SIZE) * BOX_SIZE + j;
}

void print_box(Board b, int box) {
	assert(b != NULL);
	assert(box < SIZE && box >= 0);
	
	printf("\033[0;31m");
	
	for (int i = 0; i < BOX_SIZE; i++) {
		for (int j = 0; j < BOX_SIZE; j++) {
			printf("%d ", b->board[box_row(i,box)][box_column(j,box)].value);
		}
		printf("\n");
	}
	
	printf("\033[0m");
}


// initial one, add struct
Board create_board(char *str) {
	
	FILE *file = fopen(str, "r");
	assert(file != NULL);
	char *puz = malloc(sizeof(char)*SIZE);
	assert(puz != NULL);
	
	Board new = malloc(sizeof(struct sudoku_board));
	assert(new != NULL);
	new->board = malloc(sizeof(struct sudoku_cell)*SIZE);
	assert(new->board != NULL);
	
	printf("--- Getting new board ---\n");
	
	for (int i = 0; i < SIZE; i++) {
		new->board[i] = malloc(sizeof(struct sudoku_cell)*SIZE);
		assert(new->board[i] != NULL);
		
		// add checks here - can display weird behaviour
		fgets(puz, SIZE+2, file);
		for (int j = 0; j < SIZE; j++) {
			if (isdigit(puz[j])) {
				new->board[i][j] = create_cell((int)puz[j]-'0', i, j);
			}
		}
	}
	
	// malloc for boxes
	// new->boxes = malloc(sizeof(struct sudoku_cell*)*BOX_SIZE*BOX_SIZE);
// 	assert(new->boxes != NULL);
// 	for (int i = 0; i < BOX_SIZE*BOX_SIZE; i++) {
// 		new->boxes[i] = create_box(new->board, i);
// 	}
	
	fclose(file);
	print_board(new);
	return new;
}

// redo this
Board copy_board(Board b) {
	assert(b != NULL);
	
	Board new = malloc(sizeof(struct sudoku_board));
	assert(new != NULL);
	new->board = malloc(sizeof(struct sudoku_cell)*SIZE);
	assert(new->board != NULL);
	
	for (int i = 0; i < SIZE; i++) {
		new->board[i] = malloc(sizeof(struct sudoku_cell)*SIZE);
		assert(new->board[i] != NULL);		
		for (int j = 0; j < SIZE; j++) {
			new->board[i][j] = b->board[i][j];
		}
	}
	
	return new;
}

void destroy_board(Board b) {
	assert(b != NULL);
	for (int i = 0; i < SIZE; i++) {
		free(b->board[i]);
	}
	free(b);
}

// prints out board
void print_board(Board b) {
	printf("\033[0;33m"); // makes text yellow
	
	printf(" -----------------------\n");
	for (int i = 0; i < SIZE; i++) {
		if (i < SIZE) {
			printf("| ");
		}
		for (int j = 0; j < SIZE; j++) {
			if (b->board[i][j].value) {
				printf("%d ", b->board[i][j].value);
			} else {
				printf("  ");
			}
			if ((j+1) % 3 == 0) {
				printf("| ");
			}
		}
		if (i == 2 || i == 5) {
			printf("\n|-------|-------|-------|");
		}
		printf("\n");
	}
	printf(" -----------------------\n");
	
	printf("\033[0m"); // resets text colour
}

void show_possible(Board b, int row, int column) {
	if (b->board[row][column].value != 0) {
		printf("Solved: %d\n", b->board[row][column].value);
		return;
	}
// 	printf("Hit me\n");
	for (int i = 0; i < SIZE; i++) {
		if (b->board[row][column].possible[i]) {
			printf("%d ", i+1);
		}
	}
	printf("\n");
// 	printf("\nposs: %d %d\n", row, column);
}

void print_row(Board b, int row) {
	printf("Row %d:", row+1);
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", b->board[row][i].value);
	}
	printf("\n");
}

void print_column(Board b, int column) {
	printf("Column %d:", column+1);
	for (int i = 0; i < SIZE; i++) {
		printf(" %d", b->board[i][column].value);
	}
	printf("\n");
}


// Box *create_box(Cell **b, int n) {
// 	Box *new = malloc(sizeof(struct sudoku_box));
// 	assert(new != NULL);
// 	// new->cells = malloc(sizeof(struct sudoku_cell*)*BOX_SIZE);
// // 	assert(new->cells != NULL);
// 	
// 	for (int i = 0; i < BOX_SIZE*BOX_SIZE; i++) {
// 		new->cells[i] = &(b->board[i/BOX_SIZE][i%BOX_SIZE]);
// 	}	
// 	return NULL;
// }

// 			switch(n) {
// 				case TOP_LEFT:
// 					new->cells[i][j] = b->board[i][j]; break;
// 				case TOP_MIDDLE:
// 					new->cells[i][j] = b->board[i][BOX_SIZE+j]; break;
// 				case TOP_RIGHT:
// 					new->cells[i][j] = b->board[i][2*BOX_SIZE+j]; break;
// 				case CENTRE_LEFT:
// 					new->cells[i][j] = b->board[BOX_SIZE+i][j]; break;
// 				case CENTRE_MIDDLE:
// 					new->cells[i][j] = b->board[BOX_SIZE+i][BOX_SIZE+j]; break;
// 				case CENTRE_RIGHT:
// 					new->cells[i][j] = b->board[BOX_SIZE+i][2*BOX_SIZE+j]; break;
// 				case BOTTOM_LEFT:
// 					new->cells[i][j] = b->board[2*BOX_SIZE+i][j]; break;
// 				case BOTTOM_MIDDLE:
// 					new->cells[i][j] = b->board[2*BOX_SIZE+i][BOX_SIZE+j]; break;
// 				case BOTTOM_RIGHT:
// 					new->cells[i][j] = b->board[2*BOX_SIZE+i][2*BOX_SIZE+j]; break;
// 				
// 				default:
// 					fprintf(stderr, "Invalid box number\n");
// 					exit(1);
// 			}