#include <stdint.h>
#include <8051.h>
#include <values.h>

typedef float TARGET_TYPE;
typedef long TARGET_INDEX;

void reset_values()
{
  P0 = 0;
  P1 = 0;
  P2 = 0;
  P3 = 0;
}


void fibcall(TARGET_TYPE n)
{
    TARGET_INDEX i;
    TARGET_TYPE Fnew, Fold, temp, ans;
    Fnew = 1; 
    Fold = 0;

    for(i = 2;
	      i <= n;
	      i++)
    {
      temp = Fnew;
      Fnew = Fnew + Fold;
      Fold = temp;
      //printf("Fnew: %d\n", Fnew);
    }

    ans = Fnew;

  //return ans;
}

void main()
{
  fibcall(n);
  reset_values();
}
