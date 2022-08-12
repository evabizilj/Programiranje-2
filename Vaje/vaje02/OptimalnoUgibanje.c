#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int lowLimit, upperLimit;
  //  int zap;
  //  int num;
    scanf("%d %d", &lowLimit, &upperLimit);

    int try;
    int answer;

    do
    {
      try = (lowLimit + upperLimit) / 2;
      scanf("%d", &answer);
      if (answer == 1)
      {
        lowLimit = try + 1;
      } else if (answer == - 1)
      {
        upperLimit = try - 1;
      }
    } while (answer != 0 && lowLimit <= upperLimit);

    if (lowLimit == upperLimit)
      printf("%d", lowLimit);
    else if (upperLimit > lowLimit)
      printf("%d %d", lowLimit, upperLimit);
    else
      printf("PROTISLOVJE");
    return 0;
}
