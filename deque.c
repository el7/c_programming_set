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


int view_back(struct keeper *keeper){

	printf("|----|----|\n");
	printf("| id:  %d  |\n", keeper->tail->id);
	printf("| val: %d  |\n", keeper->tail->payload);
	printf("|----|----|\n");

	return 0;
}

int view_front(struct keeper *keeper){
	printf("|----|----|\n");
	printf("| id:  %d  |\n", keeper->head->id);
	printf("| val: %d  |\n", keeper->head->payload);
	printf("|----|----|\n");

return 0;
}

int view_list(struct keeper *keeper){

	struct node *cur;
	cur = keeper->head;

	printf("\n");
	while(cur != NULL){
		printf("|----|----|\n");
		printf("| id:  %d  |\n", cur->id);
		printf("| val: %d  |\n", cur->payload);
		printf("|----|----|\n");
		cur = cur->next;
	}
	printf("\n");

	return 0;
}

int remove_node_back(struct keeper *keeper){

	if(keeper->tail != NULL){
		keeper->tail = keeper->tail->prev;
		free(keeper->tail->next);
		keeper->tail->next = NULL;
	} else printf("Deque is empty.\n");

	return 0;
}

int remove_node_front(struct keeper *keeper){

	if(keeper->head != NULL){
		keeper->head = keeper->head->next;
		free(keeper->head->prev);
		keeper->head->prev = NULL;
	} else printf("Deque is empty.\n");

	return 0;
}


int add_node_back(struct keeper *keeper){

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

	printf("What value is the payload?\n> ");
	scanf("%d", &payload);
	new_node->payload = payload;
	new_node->id = id;
	
	return 0;
}

int add_node_front(struct keeper *keeper){

	int id = keeper->top_id+1;
	keeper->top_id = id;
	int payload = 0;
	struct node *new_node;
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

	printf("What value is the payload?\n> ");
	scanf("%d", &payload);
	new_node->payload = payload;
	new_node->id = id;

	return 0;
}


int menu(){

	int selection = 0;
	printf("Select a function:\n");
	printf(" 0. Add node to back\n");
	printf(" 1. Add node to front\n");
	printf(" --------------------\n");
	printf(" 2. Remove node from back\n");
	printf(" 3. Remove node from front\n");
	printf(" -------------------------\n");
	printf(" 4. Examine last element\n");
	printf(" 5. Examine first element\n");
	printf(" 6. Examine all elements\n");
	printf("> ");

	scanf("%d", &selection);
	return selection;
}


int start(){

	struct keeper *keeper;
	keeper = (struct keeper*) malloc(sizeof(struct keeper));
	keeper->head = NULL;
	keeper->top_id = 0;
	keeper->tail = NULL;

	int selection = 0;
	while(selection != -1){
		selection = menu();
		switch(selection){
			case 0:
					add_node_back(keeper);
					break;
			case 1:
					add_node_front(keeper);
					break;
			case 2:
					remove_node_back(keeper);
					break;
			case 3:
					remove_node_front(keeper);
					break;
			case 4:
					view_back(keeper);
					break;
			case 5:
					view_front(keeper);
					break;
			case 6:
					view_list(keeper);
					break;
			case -1:
					break;
			default:
					break;
		}
	}

	return 0;
}

void desc(){
	printf("----------------------------------------------------------------\n");
	printf("A deque (or dequeue, short for double-ended-queue) is an ADT\n");
	printf("(abstract data type) which can have elements added and removed\n");
	printf("from both the front and the back.\n");
	printf("----------------------------------------------------------------\n");
	printf("\n");
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

