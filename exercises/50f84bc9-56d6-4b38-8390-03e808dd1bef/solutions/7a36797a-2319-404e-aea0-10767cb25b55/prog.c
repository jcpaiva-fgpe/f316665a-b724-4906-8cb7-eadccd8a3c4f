#include <stdio.h>

char *orient[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
//  0,  1, 2,  3, 4,  5, 6,  7

// CCW  -1   CW 1


#define FIM -1

int main()
{
  int tonto = 0, posicao = 4, sentido = -1, mov, desl;
  
  scanf("%d",&mov);
  while (mov != FIM) {
    desl = (mov%360) / 45;
    posicao = posicao + desl * sentido;
    if (posicao < 0) posicao += 8;
    else if (posicao >= 8) posicao -= 8;
    if (mov > 720) { tonto = 1; sentido = -sentido;}
    else tonto = 0;
 /*  printf("%d--(%s, %s, %s)\n",mov,orient[posicao], */
/*                 (sentido == -1? "CCW": "CW"), */
/* 	 (tonto? "tonto":"normal")); */
    scanf("%d",&mov);
  }
  
  printf("(%s, %s, %s)\n",orient[posicao],
                (sentido == -1? "CCW": "CW"),
	 (tonto? "tonto":"normal"));
  return 0;
}

