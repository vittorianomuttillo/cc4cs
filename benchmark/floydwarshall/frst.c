#include <stdint.h>
#include <values.h>

typedef float TARGET_TYPE;
typedef long TARGET_INDEX;


/*
 * The graph is rapresented with an adjacency map that contains the 
 * costs of edges between nodes 
 */

void floydwarshall(TARGET_INDEX size, TARGET_TYPE a[size][size])
{
  TARGET_INDEX i;
  TARGET_INDEX j;
  TARGET_INDEX h;

  /* 
   * The algorithm checks each path between nodes i and j that going through h node
   * if a minimum cost path is found updates the entry in b table
   */

  for(h = 0;
    h < size;
    h++)
  {
    for(i = 0;
      i < size;
      i++)
    {
      for(j = 0;
        j < size;
        j++)
      {
        if(a[i][h] + a[h][j] < a[i][j])
          a[i][j] = a[i][h] + a[h][j];
      }
    }
  }

}

void main()
{
  floydwarshall(size, a);
}
