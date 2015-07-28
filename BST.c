#include <stdio.h>
#include <stdlib.h>

/**************
 * structures *
 **************/

struct keeper{
	struct node *master_root;
	struct node *left_tail;		// farthest left  node
	struct node *right_tail;	// farthest right node
	int top_id; 
	
};

struct node{
	int id;					// node's ID
	int payload;			// node's value
	struct node *root;		// 		 root node
	struct node *left;		// left  leaf node
	struct node *right;		// right leaf node
};


/***********************
 * function prototypes *
 ***********************/

int peek_right(struct keeper *keeper);
int peek_left(struct keeper *keeper);
int peek_node(struct node *cur);
int peek_root(struct keeper *keeper);
int peek_tree(struct keeper *keeper);
int pop_left(struct keeper *keeper);
int pop_right(struct keeper *keeper);
int push_node(struct keeper *keeper);
int menu();
int start();
void desc();


/* Views largest valued node (right_tail) */
int peek_right(struct keeper *keeper){

	struct node *cur;
	cur = keeper->master_root;

	while(cur->right != NULL)
		cur = cur->right;

	if (cur != NULL){
		printf("--------\n");
		printf("id:  %d\n", cur->id);
		printf("val: %d\n", cur->payload);
		printf("--------\n");
	} else printf("\nList is empty!\n");
	
	printf("\n");

	return 0;
}


/* Views smallest valued node (left_tail) */
int peek_left(struct keeper *keeper){

	struct node *cur;
	cur = keeper->master_root;

	while(cur->left != NULL)
		cur = cur->left;

	if (cur != NULL){
		printf("--------\n");
		printf("id:  %d\n", cur->id);
		printf("val: %d\n", cur->payload);
		printf("--------\n");
	} else printf("\nList is empty!\n");
	printf("\n");

	return 0;
}

/* Views very top root node (master_root) */
int peek_root(struct keeper *keeper){

	struct node *cur;
	cur = keeper->master_root;

	if (cur != NULL){
		printf("--------\n");
		printf("id:  %d\n", cur->id);
		printf("val: %d\n", cur->payload);
		printf("--------\n");
	} else printf("\nList is empty!\n");

	printf("\n");

return 0;
}

int peek_node(struct node *root){
	
	// peek current node
	if (root == NULL){
		printf("List is empty!\n");
		return 0;
	} else {
		printf("--------\n");
		printf("id:  %d\n", root->id);
		printf("val: %d\n", root->payload);
		printf("--------\n");
	}

	// peek leaf nodes
	if (root->left != NULL)
		peek_node(root->left);

	if (root->right != NULL)
		peek_node(root->right);

	return 0;
}

/* Views all nodes in tree */
int peek_tree(struct keeper *keeper){

	printf("\n");

	// get master_root node
	struct node *cur;
	cur = keeper->master_root;

	// if not NULL, send to peek function
	if (cur == NULL) printf("List is empty!\n");
	else peek_node(cur);

	printf("\n");

	return 0;
}

/* removes node from the back (tail) */
int pop_left(struct keeper *keeper){

	struct node *cur;
	cur = keeper->left_tail;

/* NEEDS FIXING

	if(cur != NULL){
		if(cur->left != NULL){
			cur = cur->left;
			free(cur->right);
			keeper->tail = cur;			
			cur->right = NULL;
		} else {
			free(cur);
			keeper->master_root = NULL;
			keeper->tail = NULL;
		}
	} else printf("Deque is empty.\n");
*/

	return 0;
}

/* removes node from the front (master_root) */
int pop_right(struct keeper *keeper){

	struct node *cur;
	cur = keeper->right_tail;

/* NEEDS FIXING

	if(cur != NULL){
		// if more than only 1 node
		if(cur->right != NULL){			
			cur = cur->right;	
			free(cur->left);
			keeper->master_root = cur;			
			cur->left = NULL;			
		// if only 1 node			
		} else {					
			free(cur);
			keeper->master_root = NULL;
			keeper->tail = NULL;
		}
	} else printf("Deque is empty.\n");
*/

	return 0;
}

void insert(struct node *root, struct node *new_node){

	if (new_node->payload == root->payload){
		int user = 0;
		printf("Looks like this node already exists. You can...\n");
		printf(" (1) add a duplicate to its left\n");
		printf(" (2) cancel the add\n> ");
		scanf("%d", &user);
			if (user != 1)
				return;
	}

	// decide if new_node goes left or right
	if (new_node->payload > root->payload){
		if (root->right == NULL)
			root->right = new_node;
		else insert(root->right, new_node);
	} else if (new_node->payload < root->payload){
		if (root->left == NULL)
			root->left = new_node;
		else insert(root->left, new_node);
	}

}

int push_node(struct keeper *keeper){

	// create new node
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->left = NULL;
	new_node->right = NULL;

	// give values to node
	int id = keeper->top_id+1;
	keeper->top_id = id;
	new_node->id = id;

	// give values to node
	int payload = 0;
	printf("what value is the payload? (int)\n> ");
	scanf("%d", &payload);
	new_node->payload = payload;

	// create temp node
	struct node *cur = keeper->master_root;

	// figure where to put new node
	if (cur == NULL){
		printf("This is the root node!\n");
		keeper->master_root = new_node;	
	} else insert(cur, new_node);
	printf("\n");

	return 0;
}

/* Prints menu, collects user input */
int menu(){

	int selection = 0;
	printf("  Select a function:\n");
	printf("  -------------------------\n");
	printf("  1. Push node onto tree\n");
	printf("  -------------------------\n");
	printf("  2. Pop smallest node\n");
	printf("  3. Pop largest node\n");
//  printf("  ?. Pop arbitraty node\n");
	printf("  -------------------------\n");
	printf("  4. Peek root node\n");
	printf("  5. Peek smallest node\n");
	printf("  6. Peek largest node\n");
	printf("  7. Peek all nodes\n");
//  printf("  ?. Peek arbitraty node\n");
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
	keeper->master_root = NULL;
	keeper->left_tail = NULL;
	keeper->right_tail = NULL;
	keeper->top_id = 0;

	int selection = 0;
	do{
		selection = menu();
		switch(selection){
			case 1:
					push_node(keeper);
					break;
			case 2:
					pop_left(keeper);
					break;
			case 3:
					pop_right(keeper);
					break;
			case 4:
					peek_root(keeper);
					break;
			case 5:
					peek_left(keeper);
					break;
			case 6:
					peek_right(keeper);
					break;
			case 7:
					peek_tree(keeper);
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
	printf("This version (when complete) only lets you add nodes,\n");
	printf("and is balanced but doesn't re-balance.\n");
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

