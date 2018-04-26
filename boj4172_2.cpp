#include <cstdio>
#include <cmath>
#define MOD 1000000

int x[1000001] = {1, };
	
int main(void){
	for(int i=1; i<=1000000; i++){
		x[i] = (x[(int)(i-sqrt(i))] + x[(int)(log(i))] + x[(int)(i * sin(i) * sin(i))])%MOD;
	}

	int in;
	for(; scanf("%d", &in) && in != -1; ){
		printf("%d\n", x[in]);
	}
	return 0;
}