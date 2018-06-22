#include <cstdio>

int main(void){
	long long ans = 1;
	long long val[32];
	long long a, b, c;
	
	scanf("%lld %lld %lld", &a, &b, &c);
	val[0] = a;
	for(int i=1; i<=31; i++){
		val[i] = (val[i-1] * val[i-1])%c;
	}

	int mask=1;
	for(int i=0; i<31; i++){
		if( b & (mask << i) ){
			ans = (ans * val[i])%c;
		}
	}

	printf("%lld\n", ans);
	return 0;
}