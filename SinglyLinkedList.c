#include<stdio.h>
#include<stdlib.h>
struct listNode{
	int data;
	struct listNode *next;
};
int singlyListLength(struct listNode *head){
	int count=0;
	struct listNode *current=head;
	while(current!=NULL){
		count++;
		current=current->next;	
	}
	return count;
}
void insertInSinglyLinkedList(struct listNode **head, int data, int pos){
	int k=1;
	struct listNode *q,*p;
	//create a newnode
	struct listNode *newNode=(struct listNode*)malloc(sizeof(struct listNode));
	if(!newNode){
		printf("Memory Error\n");
		return;
	}
	newNode->data=data;
	p=*head;
	//beginning of the LL
	if(pos==1 || p==NULL){
		newNode->next=*head;
		*head=newNode;
	}
	else{
		//traverse to required position
		while(p!=NULL && (k<pos)){
			k++;
			q=p;
			p=p->next;
		}
		newNode->next=q->next;
		q->next=newNode;
	}
}
void deleteNodeFromLinkedList(struct listNode **head, int pos){
	int k=1;
	struct listNode *p,*q;
	p=*head;
	//empty list - give error
	if(*head==NULL){
		printf("List Empty\n");
		return;
	}
	//beginning of LL
	else if(pos==1){
		*head=(*head)->next;
		free(p);
	}
	else{
		//traverse to the required position 
		while(p!=NULL && k<pos){
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL){ // at the end
			printf("Position does not exist\n");
		}
		else{ // middle of the list
			q->next=p->next;
			free(p);
		}
	}
}
void printSLList(struct listNode *head){
	if(head==NULL){
		printf("List is empty");
	}
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

void deleteLinkedList(struct listNode **head){
	struct listNode *temp, *iter;
	iter=*head;
	while(iter){
		temp= iter->next;
		free(iter);
		iter=temp;
	}
	*head=NULL; // to change real head to point to NULL
}

int SinglyLinkedList_test(){
	struct listNode *head=NULL;
	insertInSinglyLinkedList(&head,5,1);
	insertInSinglyLinkedList(&head,4,2);
	insertInSinglyLinkedList(&head, 2, 2);
	printf("Elements in List:%d\n",singlyListLength(head));
	printSLList(head);
	deleteNodeFromLinkedList(&head,1);
	printSLList(head);
	deleteLinkedList(&head);
	printSLList(head);
	return 0;
}

int main()
{
	SinglyLinkedList_test();
}