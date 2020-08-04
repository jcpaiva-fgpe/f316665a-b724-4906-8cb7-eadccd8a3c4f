

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define ROWS 26
#define COLS 100
#define EMPTY 0
#define FULL  1

int rows, cols;  // theater dimensions

char reserve[ROWS][COLS];


/* initialize reservations */
void empty(void) {
  int i, j;
  for (i=0; i<rows; i++)
    for (j=0; j<cols; j++)
      reserve[i][j] = EMPTY;
}


/* first fit allocation
   result is 0 if failed or 1 if sucedded
 */
int first_fit(int size, int *row, int *col) {
  int i, j, k;

  assert(size>0);

  for (i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      /* look for an empty block */
      for(k=j; reserve[i][k]==EMPTY && k<cols; k++);
      if (k-j>=size) {
	*row = i;
	*col = j;
	while(size > 0) {  /* mark reservation */
	  reserve[i][j++] = FULL;
	  size--;
	}
	return 1;
      }
    }
  }
  return 0;
}


int exact_fit(int row, int col, int size) {
  int j;

  assert(0<=row && row < rows);
  assert(0<=col && col < cols);
  assert(size>0);
  assert(col + size <= cols);

  for(j=col; j<col+size; j++) {
    if(reserve[row][j] == FULL)
      return 0;  /* failed */
  }

  for(j=col; j<col+size; j++) /* mark */
    reserve[row][j] = FULL;
  return 1;
}


void get_loc(int *row, int *col) {
  char c;
  scanf("%c%d", &c, col);
  *row = c - 'A';
  *col -= 1;
  assert(0<=*row && *row<rows);
  assert(0<=*col && *col<cols);
}

void put_reply(int row, int col, int size) {
  printf("OK %c%d %d\n", row+'A',col+1, size);
}

void put_none(void) {
  printf("NA\n");
}


/* read and process a request */
void get_request(void) {
  int row, col, size;
  char c;
  scanf(" %c", &c);
  switch(c) {
  case 'X': 
    get_loc(&row,&col);
    scanf("%d", &size);
    if (exact_fit(row,col,size)) 
      put_reply(row,col,size);
    else 
      put_none();
    break;
  case 'L':
    scanf("%d", &size);
    if (first_fit(size,&row,&col)) 
      put_reply(row,col,size);
    else 
      put_none();
    break;
  default:
    printf("ERROR: invalid request");
  }
}


int main(int argc, char **argv) {
  int n; // number of requests

  scanf("%d %d %d", &rows, &cols, &n);
  
  empty();

  while(n>0) {
    get_request();
    n--;
  }
  return 0;
}
