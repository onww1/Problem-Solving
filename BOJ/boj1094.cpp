#include <cstdio>

int main(void){
	int n, i = 0, cnt = 0, pow[7] = { 64, 32, 16, 8, 4, 2, 1 };
	scanf("%d", &n);
	while(n > 0){
		if(n >= pow[i]){
			n -= pow[i];
			cnt++;
		}
		i++;
	}
	printf("%d\n", cnt);
	return 0;
}