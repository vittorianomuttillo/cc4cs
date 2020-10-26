#include <stdint.h>
#include <values.h>

typedef int8_t TARGET_TYPE;
typedef uint8_t TARGET_INDEX;

TARGET_TYPE matrix_mul(TARGET_TYPE row_num_a, TARGET_TYPE column_num_a, TARGET_TYPE a[row_num_a][column_num_a], TARGET_TYPE row_num_b, TARGET_TYPE column_num_b, 
			TARGET_TYPE b[row_num_b][column_num_b], TARGET_TYPE c, TARGET_TYPE d, TARGET_TYPE res[row_num_a][column_num_b])
{
	TARGET_INDEX i; 
	TARGET_INDEX j;
	TARGET_INDEX k = 0;
	TARGET_TYPE tot = 0;
	
	/* 
	 * If the number of columns of A is different from the b's rows number then 
	 * the multiplication can't be done 
	 */

	if(c != d)
	{
		/* Iterates through the rows of A */
		for(i = 0;
			i < row_num_a;
			i++)
		{
			/* Iterates through the columns of B */
			for(k = 0; 
				k < column_num_b;
				k++)
			{
				/* 
				 * Iterates through the columns of A. We need of the "tot" variable to remember 
				 * the value of an element in res array
				 */

				for(tot = 0, j = 0;
					j < column_num_a;
					j++)
				{
					tot += (a[i][j] * b[j][k]);
				}

				res[i][k] = tot;
			}
		}
	}
	return 0;

}



void main()
{
	TARGET_TYPE res[row_num_a][column_num_b];
	matrix_mul(row_num_a, column_num_a, a, row_num_b, column_num_b, b, c, d, res);
}
