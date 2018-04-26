#include <cstdio>


int main(void){
	int n, m, in, cnt[10001];
	int first=0, second=0;
	while(1){
		scanf("%d %d", &n, &m);
		if(n==0) break;
		for(int i=0; i<=10000; i++) cnt[i] = 0;
		first = second = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &in);
				cnt[in]++;
				if(cnt[in] > first){
					second = first;
					first = cnt[in];	
				}
			}
		}
		for(int i=1; i<=10000; i++){
			if(cnt[i] == second)
				printf("%d ", i);
		}
		puts("");
	}
	return 0;
}