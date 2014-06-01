#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL_arr_gen.h"
#include "combination.h"

void init_LL(Node *L);
Node *insert_node(Node *H, ELEM_TYPE D);
void traversal_list(Node *H);
void LL_arr_gen(int blk_num, int *length_arr, Node **node_arr);
int combination(int n, int k);

void init_LL(Node *L)
{
	L = NULL;
}

/*
 insert new node to the end of list
 */
Node *insert_node(Node *H, ELEM_TYPE D)
{
	Node *index = NULL;

	Node *tmp_node = NULL;	
	tmp_node = (Node *)malloc(sizeof(Node));
	memset(tmp_node, 0, sizeof(Node));
	
	if(tmp_node == NULL)
		printf("no space");

	tmp_node->data = D;
	tmp_node->next = NULL;

	index = H;

	if (index == NULL)
	{
		H = tmp_node;
	}
	else{
		while(index->next != NULL)
		{
			index = index->next;
		}

		index->next = tmp_node;	
	}
	return H;
}

void traversal_list(Node *H)
{
	Node *index = H;
	if(index == NULL)
		printf("\n");
	else
	{
		while(index != NULL)	
		{
			printf("%d->", index->data);	
			index = index ->next;
		}
	}
	printf("\n");
	
}

int factorial(int n)
{
	int result = 1;
	while(n > 0)		
	{
		result *= n;	
		n--;
	}
	return result;
}
int combination(int n, int k)
{
	int result = factorial(n)/(factorial(k)*factorial(n-k));	
	return result; 
}


void LL_arr_gen_func(int blk_num, int *length_arr, Node **node_arr)
{
	int v[100];
	length_arr = (int *)malloc(blk_num*sizeof(int));
	memset(length_arr,0,blk_num);
	for(int i=0;i<blk_num;i++)
	{
		length_arr[i] = combination(ELEM_LEN, i);	
	}

	char bin_ele[ELEM_LEN];
	memset(bin_ele, 0, ELEM_LEN);

	node_arr = (Node **)malloc(blk_num*sizeof(Node *));

	int *tmp_nck;
	for(int i=0;i<blk_num;i++)
	{
		ELEM_TYPE data=0;
		init_LL(node_arr[i]);
		printf("%d\n", length_arr[i]);
		tmp_nck = (int *)malloc(length_arr[i]*sizeof(int));
		int nck_index=0;
		int n = ELEM_LEN;
		if(length_arr[i] > 0)
		{

        	combinations_bin(v, 1, n, 1, i, bin_ele, ELE_LEN, tmp_nck, length_arr[i], &nck_index);
			for(int j=0;j<length_arr[i];j++)
			{
				//there is i bits in data, totally ELE_LEN C i nodes in this ll.
				//data = (ELEM_TYPE) rand(); //how to determine node value?
				node_arr[i]=insert_node(node_arr[i],tmp_nck[j]);	
			}
			traversal_list(node_arr[i]);
			printf("%d\n", node_arr[i]->data);
		}
		free(tmp_nck);
	}

}

