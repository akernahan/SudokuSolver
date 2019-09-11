#include <stdbool.h>

// these make it obvious to read
#define TRUE	1
#define FALSE	0

#define SIZE			9
#define BOX_SIZE		3

#define TOP_LEFT		0
#define TOP_MIDDLE		1
#define TOP_RIGHT		2
#define CENTRE_LEFT		3
#define CENTRE_MIDDLE	4
#define CENTRE_RIGHT	5
#define	BOTTOM_LEFT		6
#define	BOTTOM_MIDDLE	7
#define	BOTTOM_RIGHT	8

typedef  struct sudoku_cell {
	int		value;
	int		row;
	int		column;	
	int		possible[SIZE];
} Cell;

// typedef struct sudoku_box {
// // 	Cell	**cells;
// 	Cell *cells[BOX_SIZE*BOX_SIZE];
// } Box;

//typedef struct sudoku_box* Box;

struct sudoku_board {
	Cell 	**board;
// 	Box 	**boxes;
};


typedef struct sudoku_board* Board; 

Cell create_cell(int,int,int);


//Box get_box(int,int); // may take cell or row and column
// Box *create_box(Cell**,int);
int get_box(int,int);
int box_row(int,int);
int box_column(int,int);

Board create_board(char*);
Board copy_board(Board);
void destroy_board(Board);
void print_board(Board);

void show_possible(Board,int,int);
void print_row(Board,int);
void print_column(Board,int);
void print_box(Board,int);

