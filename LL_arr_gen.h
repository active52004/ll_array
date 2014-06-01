#include <limits.h> //define CHAR_BIT
#define uchar unsigned char
#define ELEM_TYPE uchar
#define ELEM_LEN CHAR_BIT

typedef struct node{
	ELEM_TYPE data;
	struct node *next;
}Node;


Node *insert_node(Node *H, ELEM_TYPE D);
void LL_arr_gen_func(Node **node_arr, int blk_num);
void init_LL(Node *L);
void traversal_list(Node *H);
int combination(int n, int k);
