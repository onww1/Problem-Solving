#include <stdio.h>

void move(int dst, int src, int* arr){
	int tmp = arr[src];
	for(int i=src-1; i>=dst; i--){
		arr[i+1] = arr[i];
	}
	arr[dst] = tmp;
}

int findMax(int sIndex, int eIndex, int* arr){
	int max = arr[sIndex], idx = sIndex;
	for(int i = sIndex+1; i <= eIndex; i++){
		if(arr[i] > max){
			max = arr[i];
			idx = i;
		}
	}
	return idx;
}

int main(void){
	int N, arr[50], S;
	while( scanf("%d", &N) != EOF ){
		for(int i=0; i<N; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &S);
		int sIndex = 0, eIndex, maxIndex;
		while(S){
			if(sIndex + S > N-1) eIndex = N-1;
			else eIndex = sIndex + S;
			maxIndex = findMax(sIndex, eIndex, arr);
			if(maxIndex == sIndex){
				if(sIndex < N-1) sIndex++;
				if(eIndex < N-1) eIndex++;
				if(sIndex == eIndex) break;
				continue;
			}
			S -= (maxIndex - sIndex);
			move(sIndex, maxIndex, arr);
			sIndex++;
		}
		for(int i=0; i<N-1; i++)
			printf("%d ", arr[i]);
		printf("%d\n", arr[N-1]);
	}
	return 0;
}