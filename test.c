#include <stdio.h>
#include <stdlib.h>
#include "./LL_arr_gen.h"

void print_arr(ELEM_TYPE *arr, int len);
void bits_freq_input(int input_blk_num, Node **index_tmp, Node **node_arr, ELEM_TYPE *input);

void main()
{
	//Node array for linkedlists
	Node **node_arr = NULL;
	int blk_num = ELEM_LEN +1;
	node_arr = (Node **)malloc(blk_num*sizeof(Node *));

	LL_arr_gen_func(node_arr, blk_num);
	/*
	for(int i=0;i< blk_num;i++)
	{
		traversal_list(node_arr[i]);		
	}
	*/

	//the linkedlist array is filled and ready to use
	int input_blk_num = 2;
	ELEM_TYPE *input;
	input = (ELEM_TYPE *)malloc(input_blk_num*sizeof(ELEM_TYPE));

	Node **index_tmp;
	index_tmp = (Node **)malloc(input_blk_num*sizeof(Node *));

 	bits_freq_input(input_blk_num, index_tmp, node_arr, input);
	
	//free tmp arrays
	for(int i=0;i<input_blk_num;i++)
	{
		free(index_tmp[i]);	
	}
	free(index_tmp);
	for(int i=0;i<blk_num;i++)
	{
		free(node_arr[i]);	
	}
	free(node_arr);

	free(input);

	exit(0);
}

void print_arr(ELEM_TYPE *arr, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d,",arr[i]);	
	}
	printf("\n");
}

void bits_freq_input(int input_blk_num, Node **index_tmp, Node **node_arr, ELEM_TYPE *input)
{
	if(input_blk_num == 2)
	{
		for(int i=0;i<= input_blk_num*ELEM_LEN;i++)
		{
			//there are i 1s
			//all input arrays stored in a file?
			int start = i>ELEM_LEN?i-ELEM_LEN:0;	
			int end = i>ELEM_LEN?ELEM_LEN:i;
			for(int j=start;j<=end;j++)	
			{
				//first blk has j 1s
				index_tmp[0] = node_arr[j];
				while(index_tmp[0] != NULL)
				{
					//second blk has i-j 1s
					index_tmp[1] = node_arr[i-j];
					input[0] = index_tmp[0]->data;	
					index_tmp[0] = index_tmp[0]->next;
					while(index_tmp[1] != NULL)
					{
						input[1] = index_tmp[1]->data; 		
						index_tmp[1] = index_tmp[1]->next;
						print_arr(input, input_blk_num);
						//use input to tag generation 
					}
				}
			}
		}
	}

}
