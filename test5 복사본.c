#include <stdio.h>

int main(void){
	double sum = 0.5;
	double prevB=0.5, curB=0.5;
	double prevF=0.5, curF=0.25;
	double P = 0.25;
	double x = 2.0;

	while(P >= 0.00000000001){
		x += 1.0;
		prevB = curB;
		prevF = curF;
		curB = 0.5 * ( prevB + prevF );
		curF = 0.5 * prevB;
		P = 0.5 * prevF;
		sum += x * P;
	}

	printf("%lf\n", sum);
	return 0;
}