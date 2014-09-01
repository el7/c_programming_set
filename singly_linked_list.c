#include <stdio.h>
#include <stdlib.h>

struct node{
	int id;
	int payload;
	struct node *next;
};

int view_list(struct node *head){

	head = head->next;
	while(head != NULL){
		printf("id:  %d\n", head->id);
		printf("val: %d\n\n", head->payload);
		head = head->next;
	}

	return 0;
}

int remove_node(struct node *head){

	int id;
	printf("Remove a node by it's ID:\n> ");
	scanf("%d", &id);
	while(head->next != NULL){
		
		if(head->next->id == id){
			struct node *temp;
			temp = head->next;
			head->next = head->next->next;
			free(temp);
		} else
			head = head->next;
		
	}

	return 0;
}



int add_node(struct node *head){

	int id = 0;
	while (head->next != NULL){
		head = head->next;
		id = head->id;
	}

	int payload = 0;
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	head->next = new_node;
	new_node->next = NULL;
	printf("What value is the payload?\n> ");
	scanf("%d", &payload);
	new_node->payload = payload;
	new_node->id = id+1;

	return 0;
}


int menu(){

	int selection = 0;
	printf("Select a function:\n");
	printf(" 0. Add node\n");
	printf(" 1. Remove node\n");
	printf(" 2. View list\n");
	printf(" 3. \n");
	printf("-1. Exit\n");
	printf("> ");

	scanf("%d", &selection);
	return selection;
}


int start(){

	struct node *head;
	head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;
	head->payload = 0;
	head->id = 0;

	int selection = 0;
	while(selection != -1){
		selection = menu();
		switch(selection){
			case 0:
					add_node(head);
					break;
			case 1:
					remove_node(head);
					break;
			case 2:
					view_list(head);
					break;
			case 3:
					break;
			case -1:
					break;
			default:
					break;
		}
	}

	return 0;
}

int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

