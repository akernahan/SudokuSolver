#include "sudoku.h"

typedef struct queue_node {
	Cell 	*c;
	struct queue_node	*next;
} Node;

struct QueueRep {
	int		exits; // counts how many nodes have left the queue
	struct queue_node	*front;
	struct queue_node	*back;
};

typedef struct QueueRep *Queue;

Queue new_queue();
void add_queue(Queue, Node*);
Node* leave_queue(Queue);
int queue_empty(Queue);
void destroy_queue(Queue);
void show_queue(Queue);

Node* create_node(Cell*);
void destroy_node(Node*);