#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

struct queue {
	Stack s1;
	Stack s2;
};

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueEnqueue(Queue q, int item) {
    StackPush(q->s1, item);
}

int QueueDequeue(Queue q) {
	if (StackSize(q->s2) == 0) {
        while (StackSize(q->s1) > 0) {
            Item elem = StackPop(q->s1);
            StackPush(q->s2, elem);
        }
    }
    return StackPop(q->s2);
}