#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};
struct Node *head=NULL;

void InsertAtFront(int value){
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=head;
	head=newNode;
	
	}
	
void InsertAtEnd(int value){
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	if(head==NULL){
	    head=newNode;
		printf("inserted %d as the first Node\n",newNode->data);
		return;
	}
	struct Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	
}

void InsertAtPos(int value,int pos){
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
    if(pos==1){
    	InsertAtFront(value);
    	return;
	}
	struct Node *temp=head;
	int count=1;
	while(temp!=NULL&&count<pos-1){
		temp=temp->next;
		count++;
	}
	if(temp==NULL){
		printf("position is out of range\n");
		free(newNode);
		return;
	}
	newNode->next=temp->next;
	temp->next=newNode;
}


void DeleteAtFront(){
	if(head==NULL){
		printf("list os empty\n");
		return;
	}
	struct Node *temp=head;
	head=head->next;
	free(temp);
}

void DeleteAtEnd(){
	if(head==NULL){
		printf("list is empty");
		return;
	}
	if(head->next==NULL){
		free(head);
		head=NULL;
	}
	struct Node *temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
}
void display(){
	struct Node *temp=head;
	if(head==NULL){
		printf("no elements in the list");
		return;
	}
	printf("linked list is:");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main(){
	InsertAtFront(20);
	InsertAtFront(10);
	InsertAtEnd(30);
	InsertAtPos(5,1);
	display();
	DeleteAtFront();
	display();
	DeleteAtEnd();
	display();
	
	return 0;
}