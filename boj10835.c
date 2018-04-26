#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, *left, *right, *dp, curL = 0, curR = 0, sum = 0;
	scanf("%d", &N);
	left  = (int*)malloc(sizeof(int) * N);
	right = (int*)malloc(sizeof(int) * N);
	dp    = (int*)malloc(sizeof(int) * N);
	for(int i=0; i<N; i++) scanf("%d", &left[i]);
	for(int i=0; i<N; i++) scanf("%d", &right[i]);

	while(curL < N && curR < N){
		if(left[curL] > right[curR]){
			sum += right[curR];
			curR++;
		} else if(left[curL] <= right[curR]){
			curL++;
			if(curL == N) break;
			else{
				if(lMax < right[curR]) curR++;
				else if(curL <= lMaxIdx) continue;
				else
			}
		}
	}

	free(left);
	free(right);
	return 0;
}