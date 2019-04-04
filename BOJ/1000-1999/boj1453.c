#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, cnt=0, in, arr[101] ={0};
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &in);
		if(arr[in] == 0) arr[in]++;
		else cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}