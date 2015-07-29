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

// pre-order
// in-order
// post-order
void search_val_helper(struct node *root, int val);
void search_val_recurs_helper(struct node *root, int val);
void search_val(struct node *root);
void search_val_recurs(struct node *root);
void peek_right(struct keeper *keeper);
void peek_left(struct keeper *keeper);
void peek_node(struct node *cur);
void peek_root(struct keeper *keeper);
void peek_tree(struct keeper *keeper);
void pop_left(struct node *root);
void pop_right(struct node *root);
void push_node(struct keeper *keeper);
int menu();
void start();
void desc();


void search_val_helper(struct node *root, int val){

	while (root != NULL){

		if (root->payload == val){
			printf("val(%d) found on node with ID(%d)\n", val, root->id);
			return;
		}
		
		if (root->payload > val)
			root = root->left;
		else if (root->payload < val)
			root = root->right;

	}
}

void search_val_recurs_helper(struct node *root, int val){

	if (root == NULL)
		return;
	if (root->payload == val){
		printf("val(%d) found on node with ID(%d)\n", val, root->id);
		return;
	} else {
		search_val_recurs_helper(root->left, val);
		search_val_recurs_helper(root->right, val);
	}
}

void search_val(struct node *root){
	
	int val = 0;
	printf("What payload value would you like to find?\n> ");
	scanf("%d", &val);
	printf("\n");
	search_val_helper(root, val);
	printf("\n");
}


void search_val_recurs(struct node *root){

	int val = 0;
	printf("What payload value would you like to find?\n> ");
	scanf("%d", &val);
	printf("\n");
	search_val_recurs_helper(root, val);
	printf("\n");
}

/* Views largest valued node (right_tail) */
void peek_right(struct keeper *keeper){

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
}


/* Views smallest valued node (left_tail) */
void peek_left(struct keeper *keeper){

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
}

/* Views very top root node (master_root) */
void peek_root(struct keeper *keeper){

	struct node *cur;
	cur = keeper->master_root;

	if (cur != NULL){
		printf("--------\n");
		printf("id:  %d\n", cur->id);
		printf("val: %d\n", cur->payload);
		printf("--------\n");
	} else printf("\nList is empty!\n");

	printf("\n");
}

void peek_node(struct node *root){
	
	// peek current node
	if (root != NULL){
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
}

/* Views all nodes in tree */
void peek_tree(struct keeper *keeper){

	// get master_root node
	struct node *cur;
	cur = keeper->master_root;

	// /////////////////////////////////////
	// SHOULD ASK USER WHAT ORDER THEY WANT:
	// In-Order
	// Pre-Order
	// Post-Order
	// /////////////////////////////////////

	// if not NULL, send to peek function
	if (cur == NULL) printf("List is empty!\n");
	else peek_node(cur);

	printf("\n");
}


/* removes smallest valued node */
void pop_left(struct node *root){

	if (root == NULL){
		printf("The tree is empty!\n");
		return;
	} else if (root->left != NULL)
		pop_left(root->left);

	// if smallest leaf has largest leaf attached, 
	// ??????????????????????????????????????????
	if (root->right != NULL){
//		root = root->right;
//		free(root->right);
//		root->right = NULL;
	} else {
		free(root);
		// make parent->left NULL
		// ???????????????????????
	}
}

/* removes largest valued node */
void pop_right(struct node *root){

	// if tree is empty, proclaim and exit.
	if (root == NULL){
		printf("The tree is empty!\n");
		return;
	} 
	// else if next leaf if not empty, recursion.
	else if (root->right != NULL)
		pop_right(root->right);

	// if largest leaf has smaller leaf attached, 
	// ??????????????????????????????????????????
	if (root->left != NULL){
//		root = root->left;
//		free(root->left);
//		root->left = NULL;
	} else {
		free(root);
		// make parent->right NULL
		// ???????????????????????
	}

	return;
}

/* recursively finds appropriate spot in tree to put node */
void insert(struct node *root, struct node *new_node){

	// if node already exists, decide what to do.
	if (new_node->payload == root->payload){
		int user = 0;
		printf("Looks like this node already exists. You can...\n");
		printf(" (1) add a duplicate to its left\n");
		printf(" (2) cancel the add\n> ");
		scanf("%d", &user);
			if (user != 1)
				return;
	}

	// if new_node is less than current node
	if (new_node->payload < root->payload){
		// if next leaf is empty, add. else, recursion.
		if (root->left == NULL) root->left = new_node;
		else insert(root->left, new_node);
	} 
	// if new_node is greater than current node
	else if (new_node->payload > root->payload){
		// if next leaf is empty, add. else, recursion.
		if (root->right == NULL) root->right = new_node;
		else insert(root->right, new_node);
	} 
}

/* creates new node, delegates to insert()  */
void push_node(struct keeper *keeper){

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

	// if tree is empty, make master_node. else, send to insert()
	if (cur == NULL) 
		keeper->master_root = new_node;	
	else 
		insert(cur, new_node);
	printf("\n");
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
	printf("  7. Peek all nodes \t\t(recurs)\n");
	printf("  -------------------------\n");
	printf("  8. Search payload value\n");
	printf("  9. Search payload value \t(recurs)\n");
	printf("  -------------------------\n");
	printf("  0. Exit\n\n");
	printf("> ");

	scanf("%d", &selection);
	printf("\n");
	return selection;
}


/* Computes the menu for the program */
void start(){

	// create, malloc, and set values for original tree keeper
	struct keeper *keeper;
	keeper = (struct keeper*) malloc(sizeof(struct keeper));
	keeper->master_root = NULL;
	keeper->left_tail = NULL;
	keeper->right_tail = NULL;
	keeper->top_id = 0;

	int selection = 0;
	do{
		// obtain user menu selection
		selection = menu();
		switch(selection){
			case 1:
					push_node(keeper);
					break;
			case 2:
					pop_left(keeper->master_root);
					break;
			case 3:
					pop_right(keeper->master_root);
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
			case 8:
					search_val(keeper->master_root);
					break;
			case 9:
					search_val_recurs(keeper->master_root);
					break;
			case 0:
					break;
			default:
					break;
		}
	}while(selection != 0);
}

/* Describes the program / concept */
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

