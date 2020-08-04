#include <stdlib.h>
#include <stdio.h>
#define SIZE 30
#define LEN 50

int grid[SIZE][SIZE];

char cmds[LEN];

int width, height, locx=0, locy=0, orient=0;

void left(void) {
  orient = (orient+3)%4;
}

void right(void) {
  orient = (orient+1)%4;
}

int forward(void) {
  int dist = 0;

  switch(orient) {
  case 0:
    while (locy+1<height && !grid[locx][locy+1]) {
      locy += 1;
      dist += 1;
    }	
    break;

  case 1:
    while (locx+1<width && !grid[locx+1][locy]) {
      locx += 1;
      dist += 1;
    }
    break;

  case 2:
    while (locy>=1 && !grid[locx][locy-1]) {
      locy -= 1;
      dist += 1;
    }
    break;

  case 3:
    while (locx>=1 && !grid[locx-1][locy]) {
      locx -= 1;
      dist += 1;
    }
    break;
  default: 
    fprintf(stderr, "invalid orientation\n");
    exit(-1);
  }
  return dist;				
}

int main(void) {
  int i, n, x,y, dist=0;

  for(x=0; x<SIZE; x++)
    for(y=0; y<SIZE; y++)
      grid[x][y]=0;

  scanf("%d\n%d\n%d\n", &width, &height, &n);
  for (i=0; i<n; i++) {
    scanf("%d\n%d\n", &x,&y);
    grid[x][y] = 1;
  }

  scanf("%s\n", cmds);

  for(i=0; cmds[i]; i++) {
    switch(cmds[i]) {
    case 'F': 
      dist += forward();
      break;
    case 'E':
      left();
      break;
    case 'D':
      right();
      break;
    default:
      fprintf(stderr, "invalid command: %c\n", cmds[i]);
      exit(-1);
      break;
    }
  }

  printf("%d\n", dist);
  exit(0);
}


