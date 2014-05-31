#include <stdio.h>
#include <stdlib.h>
#include "./LL_arr_gen.h"

int main()
{
	int blk_num = ELEM_LEN + 1;

	int *length_arr=NULL;
	Node **node_arr = NULL;

	LL_arr_gen_func(blk_num, length_arr, node_arr);

	return 0;
}

