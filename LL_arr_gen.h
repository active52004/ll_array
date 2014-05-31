#include <limits.h> //define CHAR_BIT
#define uchar unsigned char
#define ELEM_TYPE uchar
#define ELEM_LEN CHAR_BIT

typedef struct node{
	ELEM_TYPE data;
	struct node *next;
}Node;

void LL_arr_gen_func(int blk_num, int *length_arr, Node **node_arr);


