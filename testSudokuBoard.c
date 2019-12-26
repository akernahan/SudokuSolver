#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "sudoku.h"

#define MAX_STRING	128

#define BIGINNER	5
#define EASY		0
#define MEDIUM		0
#define HARD		0
#define EXPERT		0
#define MASTER		0

struct node {
	char*			filepath;
	struct node*	next;
};

struct node* create_node(char* str) {
	struct node *new = malloc(sizeof(struct node));
	assert(new != NULL);

	new->filepath = str;
	new->next = NULL;
	return new;
}

void destroy_list(struct node* l) {
	if (l == NULL) {
		return;
	}

	while (l != NULL) {
		struct node* tmp = l;
		l = l->next;
		free(tmp);
	}
}

void test_beginner() {
	char str[MAX_STRING];

	for (int i = 0; i < BIGINNER; i++) {
		snprintf(str, MAX_STRING, "puzzles/Beginner/%d.txt", i);
		printf("%s\n", str);
	}
	
}

void test_easy() {

}

void test_medium() {

}

void test_hard() {

 }

void test_expert() {

}

void test_master() {

}

int main(void) {
	// Board b = create_board("puzzles/Beginner/0.txt");
	
	test_beginner();

	//print_box(b, TOP_MIDDLE);
	// print_box(b, BOTTOM_RIGHT);
	// printf("\n");
	//b->board[8][8].value = 3;
	// print_box(b, BOTTOM_RIGHT);
	
	// destroy_board(b);	
	return 0;
}