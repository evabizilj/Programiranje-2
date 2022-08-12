#include <stdio.h>
#include <stdbool.h>

int main(){
	int numNumbers = 0;
	int number = 0;
    int max = 0;
    int drugi = 0;

	numNumbers = getchar() - '0';
	// presledek
	getchar();
	int prvi = getchar() - '0';
    max = prvi;
	while (numNumbers != 1)
	{
		// presledek
		getchar();
		number = getchar() - '0';

        if (max < number) {
            drugi = max;
            max = number;
        }

        else if (max > number && drugi <= number) {
            drugi = number;
        }

        else if (max >= number) {
            drugi = max;
        }
        
		numNumbers--;
	}

    putchar(drugi + '0');
    putchar('\n');

	return 0;
}
