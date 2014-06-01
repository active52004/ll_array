#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ELE_LEN 32

void combinations (int v[], int start, int n, int k, int maxk) {
        int     i;

        /* k here counts through positions in the maxk-element v.
         * if k > maxk, then the v is complete and we can use it.
         */
        if (k > maxk) {
                /* insert code here to use combinations as you please */
                for (i=1; i<=maxk; i++) printf ("%i ", v[i]);
                printf ("\n");
                return;
        }

        /* for this k'th element of the v, try all start..n
         * elements in that position
         */
        for (i=start; i<=n; i++) {

                v[k] = i;

                /* recursively generate combinations of integers
                 * from i+1..n
                 */
                combinations (v, i+1, n, k+1, maxk);
        }
}

/*
	@para v[]: 
	@para start:
	@para n:
	@para k:
	@para maxk:
 */
void combinations_bin (int v[], 
		int start, 
		int n, 
		int k, 
		int maxk, 
		char bin[], int bin_len) 
{
        int     i;
		memset(bin, 0, bin_len);

        /* k here counts through positions in the maxk-element v.
         * if k > maxk, then the v is complete and we can use it.
         */
        if (k > maxk) {
                /* insert code here to use combinations as you please */
                for (i=1; i<=maxk; i++) 
				{
					printf ("%i ", v[i]);
					bin[v[i]-1] = 1;
				}
                printf ("\n");
				for(i=0;i<bin_len;i++)
				{
					printf("%i ",bin[i]);
				}
				printf("\n");
                return;
        }

        /* for this k'th element of the v, try all start..n
         * elements in that position
         */
        for (i=start; i<=n; i++) {

                v[k] = i;

                /* recursively generate combinations of integers
                 * from i+1..n
                 */
                combinations_bin (v, i+1, n, k+1, maxk, bin, bin_len);
        }
}
int main (int argc, char *argv[]) {
        int     v[100], n, k;

		/*
        if (argc != 3) {
                printf ("Usage: %s n k\n", argv[0]);
                exit (1);
        }
		*/
		scanf("%d", &k);
		n = ELE_LEN;

        /* generate all combinations of n elements taken
         * k at a time, starting with combinations containing 1
         * in the first position.
         */

		char bin[ELE_LEN];
        combinations_bin (v, 1, n, 1, k, bin, ELE_LEN);
        exit (0);
}
