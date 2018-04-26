#include <cstdio>

int main(void){
	int n, h[100], sum, avg, cnt=1;

	while(1){
		scanf("%d", &n);
		if(!n) break;
		if(cnt > 1) printf("\n");
		sum = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &h[i]);
			sum += h[i];
		}
		avg = sum / n;
		sum = 0;
		for(int i=0; i<n; i++){
			if(h[i] > avg) sum += (h[i] - avg);
		}
		printf("Set #%d\n", cnt++);
		printf("The minimum number of moves is %d.\n", sum);
	}
}