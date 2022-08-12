#include <stdio.h>
#include <math.h>

int main()
{
  int lowLimit;
  int upperLimit;

  scanf("%d %d", &lowLimit, &upperLimit);

  int count = 0;

  for (int c = lowLimit; c <= upperLimit; c++)
  {
    for (int a = 1; a < c; a++)
    {
      int b2 = (c * c) - (a * a);
      int b = round(sqrt(b2));
      if (b * b == b2)
      {
        count++;
        break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
