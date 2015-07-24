#include <stdio.h>
#include <stdlib.h>

struct keeper{
	struct node *head;
	int top_id; 
	struct node *tail;
};

struct node{
	int id;
	int payload;
	struct node *prev;
	struct node *next;
};

/* Views node form back of keeper (tail) */
int peek_back(struct keeper *keeper){

	struct node *cur;
	cur = keeper->tail;

	if (cur != NULL){
		printf("--------\n");
		printf("id:  %d\n", cur->id);
		printf("val: %d\n", cur->payload);
		printf("--------\n");
	} else printf("\nQueue is empty!\n");
	printf("\n");

	return 0;
}

/* Views node from front of keeper (head) */
int peek_front(struct keeper *keeper){

	struct node *cur;
	cur = keeper->head;

	if (cur != NULL){
		printf("--------\n");
		printf("id:  %d\n", cur->id);
		printf("val: %d\n", cur->payload);
		printf("--------\n");
	} else printf("\nQueue is empty!\n");

	printf("\n");

return 0;
}

/* Views all nodes on keeper */
int peek_list(struct keeper *keeper){

	struct node *cur;
	cur = keeper->head;

	printf("\n");
	if (cur == NULL)
		printf("List is empty!\n");

	while(cur != NULL){
		printf("--------\n");
		printf("id:  %d\n", cur->id);
		printf("val: %d\n", cur->payload);
		printf("--------\n");
		cur = cur->next;
	}
	printf("\n");

	return 0;
}

/* removes node from the back (tail) */
int pop_back(struct keeper *keeper){

	struct node *cur;
	cur = keeper->tail;

	if(cur != NULL){
		if(cur->prev != NULL){
			cur = cur->prev;
			free(cur->next);
			keeper->tail = cur;			
			cur->next = NULL;
		} else {
			free(cur);
			keeper->head = NULL;
			keeper->tail = NULL;
		}
	} else printf("Queue is empty.\n");

	return 0;
}

/* removes node from the front (head) */
int pop_front(struct keeper *keeper){

	struct node *cur;
	cur = keeper->head;

	if(cur != NULL){
		// if more than only 1 node
		if(cur->next != NULL){			
			cur = cur->next;	
			free(cur->prev);
			keeper->head = cur;			
			cur->prev = NULL;			
		// if only 1 node			
		} else {					
			free(cur);
			keeper->head = NULL;
			keeper->tail = NULL;
		}
	} else printf("Queue is empty.\n");

	return 0;
}

/* adds node to keeper in the back (tail) */
int push_back(struct keeper *keeper){

	int id = keeper->top_id+1;
	keeper->top_id = id;
	int payload = 0;
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->next = NULL;

	if (keeper->tail == NULL){
		new_node->prev = NULL;
		keeper->tail = new_node;	
		keeper->head = new_node;	
	} else if (keeper->tail->next == NULL){
		new_node->prev = keeper->tail;
		keeper->tail->next = new_node;	
		keeper->tail = keeper->tail->next;	
	}

	printf("What value is the payload? (int)\n> ");
	scanf("%d", &payload);
	new_node->payload = payload;
	new_node->id = id;
	
	return 0;
}

/* adds node to keeper in the front (head) */
int push_front(struct keeper *keeper){

	int payload = 0;
	struct node *new_node;
	int id = keeper->top_id+1;
	keeper->top_id = id;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->prev = NULL;

	if (keeper->head == NULL){
		new_node->next = NULL;
		keeper->head = new_node;	
		keeper->tail = new_node;	
	} else if (keeper->head->prev == NULL){
		new_node->next = keeper->head;
		keeper->head->prev = new_node;	
		keeper->head = keeper->head->prev;	
	}

	printf("What value is the payload? (int)\n> ");
	scanf("%d", &payload);
	new_node->payload = payload;
	new_node->id = id;

	return 0;
}

/* Prints menu, collects user input */
int menu(){

	int selection = 0;
	printf("  Select a function:\n");
	printf("  -------------------------\n");
	printf("  1. Push node to back\n");
	printf("  -------------------------\n");
	printf("  2. Pop node from front\n");
	printf("  -------------------------\n");
	printf("  3. Peek first element\n");
	printf("  4. Peek all elements\n");
	printf("  -------------------------\n");
	printf("  0. Exit\n");
	printf("> ");

	scanf("%d", &selection);
	return selection;
}


/* Computes the menu for the program */
int start(){

	struct keeper *keeper;
	keeper = (struct keeper*) malloc(sizeof(struct keeper));
	keeper->head = NULL;
	keeper->top_id = 0;
	keeper->tail = NULL;

	int selection = 0;
	do{
		selection = menu();
		switch(selection){
			case 1:
					push_back(keeper);
					break;
			case 2:
					pop_front(keeper);
					break;
			case 3:
					peek_front(keeper);
					break;
			case 4:
					peek_list(keeper);
					break;
			case 0:
					break;
			default:
					break;
		}
	}while(selection != 0);

	return 0;
}

/* Describes the program */
void desc(){
	printf("----------------------------------------------------------------\n");
	printf("A queue is an ADT (abstract data type) that has the FIFO property,\n");
	printf("which can have elements added to the back and removed from the front.\n");
	printf("General functions are Peek (front), Pop (front), and Push (back).\n");
	printf("----------------------------------------------------------------\n");
	printf("\n");
}

/* Describes and starts the program */
int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

