#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#undef max
#undef min

int min(int x, int y)
{
  return x <= y ? x : y;
}

int max(int x, int y)
{
  return x >= y ? x : y;
}

void sort2(int *x, int *y)
{
  if (*x > *y)
  {
    int m = *x;
    *x = *y;
    *y = m;
  }
}

// ---------------------------------------------

void tiles(int x, int y)
{
  sort2(&x, &y);
  int a[3] = {0};
  int k = 0;
  int n = 1;

  int i;
  for (i = 1; i <= x; i++)
  {
    a[k++ % 3] += n;
    n += 2;
  }
  for (i = x+1; i <= y; i++)
  {
    a[k++ % 3] += x;
  }
  printf("%d %d %d\n", a[0], a[1], a[2]);
}


// --------------------------------

void test_once(void)
{
  int x, y;
  scanf("%d%d", &x, &y);
  tiles(x, y);
}

void test_tiles(void)
{
  int x, y;
  while (scanf("%d%d", &x, &y) != EOF)
  {
    tiles(x, y);
  }
}

// --------------------------------

char *name = "ch_in_";

void create_test_files(void)
{
  char line[1024];
  int i = 0;
  while (fgets(line, 1024, stdin) != NULL)
  {
    i++;
    char ni[1024];
    sprintf(ni, "%02d", i);
    char fn[1024];
    strcpy(fn, name);
    strcat(fn, ni);
    strcat(fn, ".txt");
    printf("%s\n", fn);
    FILE *f = fopen(fn, "w");
    int x, y;
    sscanf(line, "%d%d", &x, &y);
    fprintf(f, "%d %d\n", x, y);
    fclose(f);
  }
}

// --------------------------------

int main(int argc, char*argv[])
{
  test_once();
//  test_tiles();
//  create_test_files();
  return 0;
}
