#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#define DISCOUNT_YOUNG 25
#define DISCOUNT_FIVE_DAYS 40
#define DISCOUNT_EIGHT_DAYS 65
#define DISCOUNT_GROUP 50

int discounted(int x, int discount)
{
  return x - x * discount / 100;
}

int round_up_50(int x)
{
  int result = x;
  if (x % 50 != 0)
    result += 50 - result % 50;
  return result;
}


void curso_detailed(void)
{
  int ticket;
  int days;
  int group;
  scanf("%d%d%d", &ticket, &days, &group);
  printf("%d %d %d\n", ticket, days, group);
  int price = discounted(ticket, DISCOUNT_YOUNG);
  printf("preço com desconto: %d\n", price);
  price = round_up_50(price);
  printf("preço com desconto, arredondado: %d\n", price);
  if (days >= 8)
  {
    price = discounted(price, DISCOUNT_EIGHT_DAYS);
    printf("preço com desconto 8 dias ou mais: %d\n", price);
    price = round_up_50(price);
    printf("idem, arredondado: %d\n", price);
  }
  else if (days >= 5)
  {
    price = discounted(price, DISCOUNT_FIVE_DAYS);
    printf("preço com desconto 5 dias ou mais: %d\n", price);
    price = round_up_50(price);
    printf("idem, arredondado: %d\n", price);
  }
  else
  {
    // nothing to do
  };
  if (group >= 4)
  {
    price = discounted(price, DISCOUNT_GROUP);
    printf("preço com desconto de grupo: %d\n", price);
    price = round_up_50(price);
    printf("idem: arredondado: %d\n", price);
  }
  printf("preço final: %d\n", price);
}

void curso(void)
{
  int ticket;
  int days;
  int group;
  scanf("%d%d%d", &ticket, &days, &group);
  int price = discounted(ticket, DISCOUNT_YOUNG);
  price = round_up_50(price);
  if (days >= 8)
  {
    price = discounted(price, DISCOUNT_EIGHT_DAYS);
    price = round_up_50(price);
  }
  else if (days >= 5)
  {
    price = discounted(price, DISCOUNT_FIVE_DAYS);
    price = round_up_50(price);
  }
  else
  {
    // nothing to do
  };
  if (group >= 4)
  {
    price = discounted(price, DISCOUNT_GROUP);
    price = round_up_50(price);
  }
  printf("%d\n", price);
}

int main(int argc, char **argv)
{
  int x = 'A';
  if (argc > 1)
    x = *argv[1];
  if (x == 'A')
    curso();
  else if (x == 'B')
    curso_detailed();
  return 0;
}

