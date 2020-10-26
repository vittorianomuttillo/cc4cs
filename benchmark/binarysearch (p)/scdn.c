#include <stdint.h>
#include <values.h>
#include <8051.h>

typedef float TARGET_TYPE;
typedef long TARGET_INDEX;

TARGET_TYPE binarysearch(TARGET_INDEX n, TARGET_TYPE arr[n], TARGET_TYPE key)
{
	TARGET_TYPE l = 0;
	TARGET_TYPE r = n-1;

	while (l <= r)
	{
		TARGET_INDEX m = l + (r-l)/2;
		//TARGET_INDEX m = l + divide((r-l),2);

		if (arr[m] == key) 
			return m;  

		if (arr[m] < key) 
			l = m + 1; 
		else
			r = m - 1; 
	}

	return -1; 
}

void resetValues()
{
    P0 = 0;
    P1 = 0;
    P2 = 0;
    P3 = 0;
}

void main()
{
	binarysearch(n, arr, key);
    resetValues();
}
