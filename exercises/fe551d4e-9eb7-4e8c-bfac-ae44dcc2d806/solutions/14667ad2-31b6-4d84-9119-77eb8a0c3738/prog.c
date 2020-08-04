#include <stdio.h>

int valor(char c);

int main() {
  int arabe = 0;
  char last = 'A', a;
  
  while((a = getchar()) != '\n') {
    switch(a){
    case 'I':
      arabe += valor(last);
      last = a;
      break;
    case 'V':
      if (last == 'I')
	arabe += 4;
      else 
	arabe += 5+valor(last);
      last = 'A';
      break;
    case 'X':
	if (last == 'I') {
	  arabe += 9;
          last = 'A';
	}
	else {
	  arabe += valor(last);
	  last = 'X';
	}
	break;
    case 'L': 
      if (last == 'X') 
	arabe += 40;
      else
	arabe += 50+valor(last);
      last = 'A';
      break;
    case 'C':
      if (last == 'X') {
	arabe += 90;
	last = 'A';
      }
      else {
	arabe += valor(last);
	last = a;
      }
      break;
    case 'D':
    case 'M':
      if (last == 'C')
	arabe += valor(a)-100;
      else 
	arabe += valor(a);
      last = 'A';
    default: 
      break;
    }
  }
  arabe += valor(last);
  printf("%d\n", arabe);
  return 0;
}

int valor(char c) {
  switch(c){
  case 'I': return 1;
  case 'V': return 5;
  case 'X': return 10;
  case 'L': return 50;
  case 'C': return 100;
  case 'D': return 500;
  case 'M': return 1000;
  default: return 0;
  }
}
