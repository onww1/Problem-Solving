#include <cstdio>
#include <cmath>

int A, B, C;

double go(double x){
	return A * x + B * sin(x) - C;
}

int main(void){
	double x, val, dx; 

	scanf("%d %d %d", &A, &B, &C);
	x = (double)C/(double)A;
	dx = (double)B/(double)A;
	while(1){
		dx /= 2;
		val = go(x);
		
		if( -0.0000000000001 < val && val < 0.0000000000001) break;
		else if( val >= 0.0000000000001 ) x -= dx;
		else x += dx;
	}

	return 0;
}