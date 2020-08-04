#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1001
int p[SIZE];
int n, L;

void plot (int x, int power)
{
  int i;
  assert ((x >= 1) && (x <= L));
  p[x] += power;
  for (i = 1; power - i > 0; i ++)
    {
      if (x - i >= 1) p[x - i] += power - i;
      if (x + i <= L) p[x + i] += power - i;
    }
}

void input (void)
{
  int i, x, power;
  memset (p, 0, sizeof (p));
  assert (scanf ("%d %d", &L, &n) == 2);
  assert ((L >= 1) && (L <= 1000));
  assert ((n >= 1) && (n <= 1000));
  for (i = 0; i < n; i ++)
    {
      assert (scanf ("%d %d", &x, &power) == 2);
      assert ((x >= 1) && (x <= L));
      assert ((power >= 1) && (power <= 64));
      plot (x, power);
    }
}

void solve (void)
{
  int m, x, power;
  assert (scanf ("%d", &m) == 1);
  assert ((m >= 1) && (m <= 500));
  while (m -- > 0)
    {
      assert (scanf ("%d %d", &x, &power) == 2);
      assert ((x >= 1) && (x <= L));
      assert ((power >= 1) && (power <= 64));
      if (p[x] >= power)
        printf ("SIM\n");
      else
        printf ("NAO\n");
    }
}

int main (void)
{
  input ();
  solve ();
  return (0);
}
