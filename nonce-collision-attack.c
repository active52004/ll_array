#include <stdio.h>
#include <stdlib.h>
#define uchar unsigned char
#define ELEM_TYPE uchar


typedef struct node Node;
struct node{
	ELEM_TYPE data;
	struct node *next;
};

void init_LL(Node *L);
void init_LL_data(Node *L, ELEM_TYPE D);
void insert_node(Node *L, ELEM_TYPE D, Node *P);

int main()
{
	Node *H;
	init_LL_data(H, (ELEM_TYPE));
	printf("%d\n", H->data);

}
void init_LL(Node *L)
{
	L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
}
void init_LL_data(Node *L, ELEM_TYPE D)
{
	L = (Node*)malloc(sizeof(Node));
	L->data = D;
	L->next = NULL;
}

/*
   insert a node with data after P
 * @para LinkedList L: head of list
 * @para ELEM_TYPE data: data of node
 * @para position P: the position
 **/
void insert_node(Node *L, ELEM_TYPE D, Node *P)
{
	Node *tmp = NULL;	
	tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
		printf("out of space");

	tmp->next = P->next;
	P->next = tmp;
	tmp->data = D;
}
