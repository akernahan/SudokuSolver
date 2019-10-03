//#include "sudoku.h"
#include "Queue.h"

void init_queue(Queue, Board);

void remove_possible(Board, Node*);
void remove_possible_row(Board,int,int);
void remove_possible_column(Board,int,int);
void remove_possible_box(Board,Node*);

void solve_board(Board,Queue);
void add_solution(Queue,Cell*);


