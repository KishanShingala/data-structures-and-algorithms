#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node* next;
};

void printList(struct node *);
void insertFirst(struct node **,int);
void insertLast(struct node **,int);
void insertAtpossition(struct node **,int,int);
void insertAfter(struct node *,int);
void deletfirst(struct node **);
void deletLast(struct node **);

int main(){
	struct node* head = NULL;
	struct node* second  = NULL;
	struct node* third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	second->data = 2;
	third->data = 3;

	head->next = second;
	second->next = third;

	printList(head);

	insertFirst(&head,10);
	insertLast(&head,10);
	insertAtpossition(&head,10,2);
	insertAfter(head->next->next,15);
	deletfirst(&head);
	deletLast(&head);
	printList(head);

	return 0;
}
void printList(struct node* n){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = n;

	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}

	printf("\n");
	free(temp);
}

void insertFirst(struct node **n,int data){
	struct node* new = (struct node*)malloc(sizeof(struct node));

	new->data = data;
	new->next = (*n);
	(*n) = new;
}

void insertLast(struct node **n,int data){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	struct node* last = (*n);
	
	while(last->next!=NULL)
		last = last->next;

	new->data = data;
	last->next = new;
	new->next = NULL;

}

void insertAtpossition(struct node **n,int data,int pos){
	int k = 1;
	struct node* new = (struct node*)malloc(sizeof(struct node));
	struct node* last = (*n);
	
	while(last->next!=NULL && k<pos){
		last = last->next;
		k++;
	}
	
	new->next = last->next;
	new->data = data;
	last->next = new;

}
void insertAfter(struct node *n,int data){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	
	new->data = data;
	new->next = n->next;
	n->next = new;
}
void deletfirst(struct node** n){
	struct node *temp = (*n);
	(*n) = (*n)->next;
	free(temp);
}
void deletLast(struct node **n){
	struct node *temp = (*n);

	while(temp->next->next!=NULL)
		temp=temp->next;

	free(temp->next);
	temp->next = NULL;
}