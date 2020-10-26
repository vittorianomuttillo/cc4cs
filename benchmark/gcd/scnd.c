#include <stdint.h>
#include <8051.h>
#include <values.h>

typedef int16_t TARGET_TYPE;
typedef int8_t TARGET_INDEX;

TARGET_TYPE modulo(TARGET_TYPE x, TARGET_TYPE y)
{
    TARGET_TYPE result = x; 
      
    while (result >= y)
        result -= y;

    return result;
}

TARGET_TYPE gcd(TARGET_TYPE m, TARGET_TYPE n)
{

    TARGET_TYPE r = 0;

    if(m == 0 && n == 0)
        return -1;

    if(m < 0) 
        m = -m;
    if(n < 0)
        n = -n;


    while(n) 
    {
        r = modulo(m,n);
        m = n;
        n = r;
    }

    return m;
}


void main()
{
    gcd(m, n);
    reset_values();
}
