#include <stdio.h>
#include <stdbool.h>

#include "sudoku.h"

int main(void) {
	Board b = create_board("puzzles/0.txt");
	
// 	printf("Board size: %lu\n", sizeof(struct sudoku_board));
// // 	printf("Box size: 	%lu\n", sizeof(struct sudoku_box));
// 	printf("Cell size:	%lu\n", sizeof(struct sudoku_cell));
// 	printf("Bool size:	%lu\n", sizeof(b->board[0][0].possible));
// 	printf("%p\n%p\n%d\n", b->board, b->board[0], 0);
	
	//print_box(b, TOP_MIDDLE);
	print_box(b, BOTTOM_RIGHT);
	printf("\n");
	//b->board[8][8].value = 3;
	print_box(b, BOTTOM_RIGHT);
	
	//destroy_board(b);	
	return 0;
}