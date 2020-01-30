# Makefile for sudoku Solver

CC = gcc
CFLAGS= -Wall -Werror -gdwarf-2

all : testSudokuBoard

testSudokuBoard : testSudokuBoard.c sudokuSolver.c sudoku.c Queue.c
	$(CC) -o testSudokuBoard testSudokuBoard.c sudokuSolver.c sudoku.c Queue.c

# sudokuSolver : sudokuSolver.c Queue.c sudoku.c
# 	$(CC) -o sudokuSolver sudokuSolver.c sudoku.c Queue.c 