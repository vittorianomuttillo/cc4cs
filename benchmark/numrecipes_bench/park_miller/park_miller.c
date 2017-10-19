#include <stdio.h>
#include <stdint.h>
#include <8051.h>
#include <values.h>

typedef int8_t TARGET_TYPE;
typedef int8_t TARGET_INDEX;

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

void prototype(int8_t idum);

float ran0()
/*
“Minimal” random number generator of Park and Miller. Returns a uniform random deviate
between 0.0 and 1.0. Set or reset idum to any integer value (except the unlikely value MASK )
to initialize the sequence; idum must not be altered between calls for successive deviates in
a sequence.
*/

{
	TARGET_TYPE k;
	TARGET_TYPE ans;

	idum ^= MASK;
	
	k=(idum)/IQ;
	idum = IA * ( idum - k * IQ) - IR * k;
	if(idum < 0)
		idum += IM;
	ans = AM * idum;
	idum ^= MASK;
	
	return ans;
}


void main()
{
	ran0();
}