#include <stdio.h>
#include <stdbool.h>

int main(){
	int numNumbers = 0;
	int number = 0;

	bool enak = true;

	numNumbers = getchar() - '0';
	// presledek
	getchar();
	int prvi = getchar() - '0';
	while (numNumbers != 1)
	{
		// presledek
		getchar();
		number = getchar() - '0';
		if (number != prvi)
			enak = false;
		numNumbers--;
	}

	if (enak)
		putchar('1');
	else
		putchar('0');
	putchar('\n');
	
	return 0;
}
