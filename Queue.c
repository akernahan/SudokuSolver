#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Queue.h"

Queue new_queue() {
	Queue new = malloc(sizeof(struct QueueRep));
	assert(new != NULL);
	
	new->exits = 0;
	new->front = new->back = NULL;
	
	return new;
}

void add_queue(Queue q, Node *n) {
	assert(q != NULL);
	assert(n != NULL);
	
	// case for nothing in queue
	if (q->front == NULL) {
		q->front = q->back = n;
		return;
	}
	
	// main case
	q->back->next = n;
	q->back = n;
	
}

Node* leave_queue(Queue q) {
	if (q->front == NULL) {
		q->back = NULL;
		return NULL;
	}
	
	Node *t = q->front;
	q->front = q->front->next;
	q->exits += 1;
	return t;
}

int queue_empty(Queue q) {
	if (q->front != NULL) {
		return 1; // true
	}
	return 0; // false
}

void destroy_queue(Queue q) {
	assert(q != NULL);
	
	while(q->front != NULL) {
		Node *tmp = q->front;
		q->front = q->front->next;
		free(tmp);
	}
	free(q);
}

void show_queue(Queue q) {
	assert(q != NULL);
	
	if (q->front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	
	printf("Current Queue:\n");
	
	int i = 1;
	for (Node *tmp = q->front; tmp != NULL; tmp = tmp->next) {
		if (tmp->next == NULL) {
			printf("%d(%d,%d)\n", tmp->c->value, tmp->c->row+1, tmp->c->column+1);
		} else {
			printf("%d(%d,%d) ", tmp->c->value, tmp->c->row+1, tmp->c->column+1);
		}
		if (i % 5 == 0) {
			printf("\n");
		}
		i++;
	}
}


// Node functions

Node* create_node(Cell *cell) {
	Node *new = malloc(sizeof(struct queue_node));
	assert(new != NULL);
	
	new->c = cell;
	new->next = NULL;
	// new->val = v;
// 	new->row = x;
// 	new->column = y;
// 	new->next = NULL;
	
	return new;
}
// not really needed
void destroy_node(Node* n) {
	assert(n != NULL);
	free(n);
}