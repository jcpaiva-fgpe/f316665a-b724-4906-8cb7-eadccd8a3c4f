#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE,TRUE} Bool;

typedef struct {
  int n;
  Bool *used;
  int *matrix;
} SQUARE;

#define MATRIX(matrix,n,i,j) (matrix)[(i)*(n)+(j)]

SQUARE *allocate_and_read_square()
{
  int n;
  int i,j;
  SQUARE *square;
   
  /* Read dimension from stdin  */
  scanf("%d",&n);

  /* Allocate space for a SQUARE of dimension nxn  */

  if((square = (SQUARE *)malloc(sizeof(SQUARE))) == NULL )
    {
      perror("Could not allocate space for SQUARE struct\n");
      exit(1);
    }

  square->n = n;

  if((square->used = (Bool *)malloc(n*n*sizeof(Bool))) == NULL )
  {
    free((void *)square);
    perror("Could not allocate space for used array of the SQUARE struct\n");
    exit(2);
  }
  

  if((square->matrix = (int *)malloc(n*n*sizeof(int))) == NULL )
  {
    free((void *)square->used);
    free((void *)square);
    perror("Could not allocate space for the integer matrix of the SQUARE struct\n");
    exit(3);
  }
  
  
  /* Initialize Boolean array with False */
  memset((void *)(square->used),FALSE,n*n*sizeof(Bool));

  /* Read square matrix numbers from stdin */
  for(i = 0; i< n; i++)
    for(j = 0; j< n; j++)
      scanf("%d",&(MATRIX(square->matrix,n,i,j)));
  
  return square;
}
  

int magic_of(SQUARE *square)
{
  int n = square->n;
  int i,j;
  int *matrix = square->matrix;
  /* int magic= (n*(n*n+1))/2; */
  /*   I want a solution that does not use the formula */
  int magic=0;
  int diag1, diag2;
  
  /*Determine Magic... */
  for(j=0; j < n; j++)
    {
      magic+=MATRIX(matrix,n,0,j);
      square->used[MATRIX(matrix,n,0,j)-1] = TRUE;
    }
  
  /* Verify the rest of the rows */
  for(i = 1; i < n; i++ )
    {
      int sum = 0;
      
      for(j = 0; j < n; j++ )
	{
	  sum += MATRIX(matrix,n,i,j);
	  square->used[MATRIX(matrix,n,i,j)-1] = TRUE;
	}
      
      if(sum != magic) return 0;
    }

  /* printf("Passed Rows\n"); */

  /* Verify n columns */
  for(j = 0; j < n; j++ )
  {
    int sum = 0;
      
    for(i = 0; i < n; i++ )
      sum += MATRIX(matrix,n,i,j);
      
    if(sum != magic) return 0;
  }

  /* printf("Passed Columns\n"); */

  /* Verify diagonals */
  diag1 = diag2 = 0;
  for(i = 0; i < n; i++ )
    {
      diag1 += MATRIX(matrix,n,i,i);
      diag2 += MATRIX(matrix,n,i,n-1-i);
    }

  if(diag1 != magic || diag2 != magic ) return 0;

  /* printf("Passed Diags\n"); */

  /* Verify all numbers [1..nxn] appear on the square */
  for(i = 0; i < n*n-1; i++ )
    {
      if(!square->used[i])
	{
	  /*printf("Failed because %d is not used in the square\n", i+1); */
	  return 0;
	}
    }

  /* If it reaches this point the square is magic */
  return magic;
}
  

void display(SQUARE *square)
{
  int n = square->n;
  int i,j;

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	printf("%d ", MATRIX(square->matrix,n,i,j));

      puts("");
    }
}


void free_square(SQUARE *magic)
{
  free((void *) magic->used);
  free((void *) magic->matrix);
  free((void *) magic);
}


int main()
{
      SQUARE *magic = allocate_and_read_square();
      /* display(magic); */
      printf("%d\n",magic_of(magic));
      free_square(magic);

      return 0;

}
