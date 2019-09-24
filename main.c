#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double calc_term(int n, double t)
{
	double value = 0;
	switch (n)
	{
	case 1:
		value = 1;
		return value;
		break;
	case 2:
		value = -t;
		return value;
		break;
	case 3:
		value = ((-t) * (-t) * (-t)) / 3;
		return value;
		break;
	case 4: 
		value = ((-t) * (-t) * (-t) * (-t)) / 6;
		return value;
		break;
	case 5:
		value = ((-t) * (-t) * (-t) * (-t) * (-t)) / 30;
		return value;
		break;
	case 6:
		value = ((-t) * (-t) * (-t) * (-t) * (-t) * (-t) * (-t)) / 630;
		return value;
		break;
	}
}

double rel_error(double exact, double series)
{
	return 100 * ((exact - series) / exact);
}

double trunc_error(int n, double t, double series)
{
	double first_trunc = calc_term(n + 1, t);
	return 100 * (first_trunc / series);
}

int main()
{
	int choice = 0;
	while (choice != 2)  
	{
		printf("Evaluate the Maclaurin Series approximation to exp(-t)*cos(t) \n");
		printf("1: Evaluate the series\n");
		printf("2: quit\n");
		scanf(" %d", &choice);
		
		if (choice == 1)
		{
			int n = 0;
			double t = 0;
			double sum = 0;
			double inc = 0;
			double counter = 0;
			double exact = 0;
			do {
				printf("Please enter the number of terms in the series(MAX: 5):\n");
				scanf("%d", &n);
				getchar();
				if (n < 0 || n > 5) {
					printf("Invalid number of terms.\n");
				}
			} while (n < 0 || n > 5);

			do {
				printf("Please enter a range between 0 and 2:\n");
				scanf("%lf", &t);
				getchar();
				if (t < 0 || t > 2) {
					printf("That number is outside the range of 0 - 2.\n");
				}
				else {
					inc = t / 10;
				}
			} while (t < 0 || t > 2);
			
			printf(" %20s %20s %20s %20s %20s\n", "t","Series","Exact","Exact %% Error", "Trunc. %% Error");
			
			while(counter <= t) {
				for (int j = 1; j <= n; j++) {
					sum += calc_term(j, counter);
				}
				exact = exp(-counter) * cos(counter);
				printf("%20e %20e %20e %20e %20e\n", counter, sum, exact, rel_error(exact,sum), trunc_error(n, inc, sum));
				sum = 0;
				counter += inc;
			}
		}
	} 
	

	return 0;
}