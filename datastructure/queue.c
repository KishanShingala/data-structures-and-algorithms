#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int capacity;
	int front,rear;
	int *arry;
};

void hello(){
	printf("hell from queue\n");
}
struct Queue* cretaqueue(int capacity){
	struct Queue* q = malloc(sizeof(struct Queue));
	if(!q){
		printf("insuficent memory\n");
		return;
	}
	q->capacity = capacity;
	q->front=q->rear = -1;
	q->arry = malloc(sizeof(int)*q->capacity);
	if(!q->arry){
		printf("insuficent memory\n");
		return;
	}
	return q;
} 

int isempty(struct Queue *q){   
	return(q->front == -1);
}

int isfull(struct Queue *q){
	return((q->rear+1)%q->capacity == q->front);
}
int queuesize(struct Queue *q){
	return((q->capacity - q->front + q->rear + 1)%q->capacity);
}
void enqueue(struct Queue *q,int data){
	if(isfull(q)){
		printf("queue is full\n");
		return;
	}
	else{
		q->rear = (q->rear + 1)%q->capacity;
		q->arry[q->rear] = data;
		if(q->front == -1)
			q->front = q->rear;
	}
}
int dequeue(struct Queue *q){
	if(isempty(q)){
		printf("queue is empty\n");
		return -1;
	}
	else{
		int data = q->arry[q->front];
		if(q->front==q->rear)
			q->front=q->rear=1;
		else
			q->front = (q->front + 1)%q->capacity;
		return data;
	}
}