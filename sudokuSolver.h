#include "Queue.h"
#ifndef SUDOKU_H
#define SUDOKU_H

void init_queue(Queue, Board);

void remove_possible(Board, Node*);
void remove_possible_row(Board,int,int);
void remove_possible_column(Board,int,int);
void remove_possible_box(Board,Node*);

void solve_puzzle(Board);
void fill_board(Board,Queue);
void add_solution(Queue,Cell*);

/* 
    functions for backtrack method 
*/
struct board_pos {
    int row;
    int column;
    int count;
};
typedef struct board_pos *Coords;

int backtrack_solve(Board,Coords);
int find_empty(Board,Coords);
int is_safe(Board,int,int,int);
int safe_row(Board,int,int);
int safe_col(Board,int,int);
int safe_box(Board,int,int);
Coords create_coords();

#endif
