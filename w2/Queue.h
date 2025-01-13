typedef struct queue *Queue;

Queue QueueNew(void);
void QueueEnqueue(Queue q, int item);
int QueueDequeue(Queue q);