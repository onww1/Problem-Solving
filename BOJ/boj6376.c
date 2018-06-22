#include <stdio.h>

int fac[10] = {1, 1, 2, 6};

int factorial(int n){
	if(fac[n] != 0) return fac[n];
	else return fac[n] = n * fac[n-1];
}

int main(void){
	double e = 2.5;

	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(int i=3; i<10; i++){
		e += 1.0/(double)factorial(i);
		printf("%d %.9f\n", i, e);		
	}
	return 0;
}