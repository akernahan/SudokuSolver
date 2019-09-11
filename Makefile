# Makefile for sudoku Solver

CC = gcc
CFLAGS= -Wall -Werror -gdwarf-2

all : testSudokuBoard sudokuSolver

testSudokuBoard : testSudokuBoard.c sudoku.c
	$(CC) -o testSudokuBoard testSudokuBoard.c sudoku.c

sudokuSolver : sudokuSolver.c Queue.c sudoku.c
	$(CC) -o sudokuSolver sudokuSolver.c sudoku.c Queue.c 