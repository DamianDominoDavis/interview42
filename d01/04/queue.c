#include "header.h"

struct s_queue *queueInit(void) {
	struct s_queue *q = 0;
	if ((q = malloc(sizeof(struct s_queue))))
		*q = (struct s_queue){0, 0};
	return q;
}

int isEmpty(struct s_queue *queue) {
	return (queue && !queue->first);
}

char *peek(struct s_queue *queue) {
	return (queue && queue->first)? queue->first->message : 0;
}

void enqueue(struct s_queue *queue, char *message) {
	if (queue && message) {
		if (!queue->first)
		 	queue->first = queue->last = malloc(sizeof(struct s_node));
		else
			queue->last = queue->last->next = malloc(sizeof(struct s_node));
		*queue->last = (struct s_node){message, 0};
	}
}

char *dequeue(struct s_queue *queue) {
	char *out = peek(queue);
	struct s_node *tmp;

	if (queue && queue->first) {
		if (queue->first == queue->last) {
			free(queue->first);
			queue->first = queue->last = 0;
		}
		else {
			tmp = queue->first;
			queue->first = queue->first->next;
			free(tmp);
		}
	}
	return out;
}
