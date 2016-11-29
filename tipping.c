#include <stdio.h>

int main() {
	double bill; // it's in dollars
	double tip10, tip15, tip20;

	//prompt of the bill
	printf("Please enter the bill total: ");
	scanf("%lf", &bill);

	tip10 = bill * 0.1;
	tip15 = bill * 0.15;
	tip20 = bill * 0.2;

	printf("A 10%% tip is %.2lf\n", tip10);
	printf("A 15%% tip is %.2lf\n", tip15);
	printf("A 20%% tip is %.2lf\n", tip20);

	return 0;
}
