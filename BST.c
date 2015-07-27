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
	struct node *left;
	struct node *right;
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
	} else printf("\nList is empty!\n");
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
	} else printf("\nList is empty!\n");

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
		cur = cur->right;
	}
	printf("\n");

	return 0;
}

/* removes node from the back (tail) */
int pop_back(struct keeper *keeper){

	struct node *cur;
	cur = keeper->tail;

	if(cur != NULL){
		if(cur->left != NULL){
			cur = cur->left;
			free(cur->right);
			keeper->tail = cur;			
			cur->right = NULL;
		} else {
			free(cur);
			keeper->head = NULL;
			keeper->tail = NULL;
		}
	} else printf("Deque is empty.\n");

	return 0;
}

/* removes node from the front (head) */
int pop_front(struct keeper *keeper){

	struct node *cur;
	cur = keeper->head;

	if(cur != NULL){
		// if more than only 1 node
		if(cur->right != NULL){			
			cur = cur->right;	
			free(cur->left);
			keeper->head = cur;			
			cur->left = NULL;			
		// if only 1 node			
		} else {					
			free(cur);
			keeper->head = NULL;
			keeper->tail = NULL;
		}
	} else printf("Deque is empty.\n");

	return 0;
}

/* adds node to keeper in the back (tail) */
int push_back(struct keeper *keeper){

	int id = keeper->top_id+1;
	keeper->top_id = id;
	int payload = 0;
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->right = NULL;

	if (keeper->tail == NULL){
		new_node->left = NULL;
		keeper->tail = new_node;	
		keeper->head = new_node;	
	} else if (keeper->tail->right == NULL){
		new_node->left = keeper->tail;
		keeper->tail->right = new_node;	
		keeper->tail = keeper->tail->right;	
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
	new_node->left = NULL;

	if (keeper->head == NULL){
		new_node->right = NULL;
		keeper->head = new_node;	
		keeper->tail = new_node;	
	} else if (keeper->head->left == NULL){
		new_node->right = keeper->head;
		keeper->head->left = new_node;	
		keeper->head = keeper->head->left;	
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
	printf("  - PROGRAM DOES NOTHING -\n");
	printf("  -------------------------\n");
	printf("  Select a function:\n");
	printf("  -------------------------\n");
//	printf("  1. Push node to front\n");
//	printf("  2. Push node to back\n");
	printf("  -------------------------\n");
//	printf("  3. Pop node from front\n");
//	printf("  4. Pop node from back\n");
	printf("  -------------------------\n");
//	printf("  5. Peek first element\n");
//	printf("  6. Peek last element\n");
//	printf("  7. Peek all elements\n");
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
//					push_front(keeper);
					break;
			case 2:
//					push_back(keeper);
					break;
			case 3:
//					pop_front(keeper);
					break;
			case 4:
//					pop_back(keeper);
					break;
			case 5:
//					peek_front(keeper);
					break;
			case 6:
//					peek_back(keeper);
					break;
			case 7:
//					peek_list(keeper);
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
	printf("A Binary Searh Tree (BST) is a data structure\n");
	printf("BST -- each node has up to two leaf nodes, a left and a right.\n");
	printf("The left leaf is always less than the node.\n");
	printf("The right leaf is always more than the node.\n");
	printf("\n");
	printf("This version (when complete) only lets you add nodes\n");
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

