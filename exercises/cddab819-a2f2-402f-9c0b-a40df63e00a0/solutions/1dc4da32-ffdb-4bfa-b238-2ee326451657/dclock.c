#include <stdio.h>

char seg[7][10] = {
   {'-',' ','-','-',' ','-','-','-','-','-'},
   {'|',' ',' ',' ','|','|','|',' ','|','|'},
   {'|','|','|','|','|',' ',' ','|','|','|'},
   {' ',' ','-','-','-','-','-',' ','-','-'},
   {'|',' ','|',' ',' ',' ','|',' ','|',' '},
   {'|','|',' ','|','|','|','|','|','|','|'},
   {'-',' ','-','-',' ','-','-',' ','-','-'}};

void print_time(int h1, int h2, int m1, int m2) {
   printf(" %c   %c   %c   %c \n", seg[0][h1], seg[0][h2], seg[0][m1],
         seg[0][m2]);
   printf("%c %c %c %c %c %c %c %c\n", seg[1][h1], seg[2][h1], seg[1][h2],
         seg[2][h2], seg[1][m1], seg[2][m1], seg[1][m2], seg[2][m2]);
   printf(" %c   %c : %c   %c \n", seg[3][h1], seg[3][h2], seg[3][m1],
         seg[3][m2]);
   printf("%c %c %c %c %c %c %c %c\n", seg[4][h1], seg[5][h1], seg[4][h2],
         seg[5][h2], seg[4][m1], seg[5][m1], seg[4][m2], seg[5][m2]);
   printf(" %c   %c   %c   %c \n", seg[6][h1], seg[6][h2], seg[6][m1],
         seg[6][m2]);
}

int main(int argc, char ** argv) {
   char h1, h2, m1, m2;
   scanf("%c%c:%c%c", &h1, &h2, &m1, &m2);
   print_time(h1-'0', h2-'0', m1-'0', m2-'0');
   return 0;
}

