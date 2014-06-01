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
/*
int main (int argc, char *argv[]) {
        int     v[100], n, k;

        if (argc != 3) {
                printf ("Usage: %s n k\n", argv[0]);
                exit (1);
        }
		scanf("%d", &k);
		n = ELE_LEN;

        
		char bin[ELE_LEN];

		int *tmp_nck;
		int nck_len = combination(n, k);
		tmp_nck = (int *)malloc(nck_len * sizeof(int));
		int nck_index =0;

        combinations_bin (v, 1, n, 1, k, bin, ELE_LEN, tmp_nck, nck_len, &nck_index);

		Node *H = NULL;
		init_LL(H);
		for(int i=0;i<nck_len;i++)
		{
			H= insert_node(H, (ELEM_TYPE) tmp_nck[i]);	
		}
		traversal_list(H);

		free(tmp_nck);
        exit (0);

}
*/
