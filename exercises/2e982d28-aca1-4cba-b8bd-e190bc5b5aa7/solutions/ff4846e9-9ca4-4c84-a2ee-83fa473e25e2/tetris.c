#include <stdio.h>
#include <string.h>

#define DIM_X    8
#define DIM_Y   15
#define PIECE_X  4
#define PIECE_Y  4

#define EMPTY '.'
#define PIECE '#'

char board[DIM_Y][DIM_X];

void init_board() {
  memset(board,EMPTY,sizeof(board));  
}

void print_board() {
  int i,j;
  for (i=0;i<DIM_Y;i++) {
    for (j=0;j<DIM_X;j++)
      putchar(board[i][j]);
    putchar('\n');
  }
}

void read_pieces() {
  int i,j,k,npieces,piece_x,piece_y,x,y;
  char piece[PIECE_Y][PIECE_X+1],flag;
  scanf("%d",&npieces);
  for (i=0;i<npieces;i++) {
    scanf("%d %d %d",&piece_y,&piece_x,&x); x--;
    for (j=0;j<piece_y;j++) scanf("%s",piece[j]);
    
    /* Look for the first line that "stops" piece */
    flag=0;
    for (y=0;!flag && y+piece_y<=DIM_Y;y++) {      
      for (j=0;!flag && j<piece_y;j++)
	for (k=0;!flag && k<piece_x;k++)
	  if (piece[j][k]==PIECE && board[y+j][x+k]==PIECE) {
	    y--;
	    flag=1;
	  }
    }

    /* Draw the piece on it's place */
    y--;
    for (j=0;j<piece_y;j++)
      for (k=0;k<piece_x;k++)
	if (piece[j][k]==PIECE) board[y+j][x+k]=PIECE;

    /* Check for lines made */
    for (y=DIM_Y-1;y>=0;y--) {
      for (x=0;x<DIM_X;x++) if (board[y][x]==EMPTY) break;
      if (x==DIM_X) {
	for (j=y;j>0;j--)
	  for (k=0;k<DIM_X;k++)
	    board[j][k]=board[j-1][k];
	y++;
	}
    }
  }  
}

int main() {

  init_board();
  read_pieces();
  print_board();

  return 0;
}
