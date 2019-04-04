#include <stdio.h>
#include <stdlib.h>

void merge2(int* arr, int i, int mid, int t){
	int* tmp = (int*)malloc(sizeof(int) * (t-i+1));
	int a = i, b = mid+1, c=0;
	while(a<=mid && b<=t){
		if(arr[a] < arr[b]){
			tmp[c++] = arr[a++];
		}
		else if(arr[a] > arr[b]){
			tmp[c++] = arr[b++];
		} 
		else if(arr[a] == arr[b]){ 
			tmp[c++] = arr[a++];
			tmp[c++] = arr[b++];
		}
	}
	while(a<=mid){
		tmp[c++] = arr[a++];
	}
	while(b<=t){
		tmp[c++] = arr[b++];
	}
	for(int j=i, k=0; j<=t; j++, k++) arr[j] = tmp[k];
	free(tmp);
	return;
}

void mergesort2(int* arr, int i, int t){
	if(i==t) return;
	int mid = (i+t)/2;
	mergesort2(arr, i, mid);
	mergesort2(arr, mid+1, t);
	merge2(arr, i, mid, t);
	return;
}

int main(void){
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	mergesort2(arr, 0, N-1);
	for(int i=0; i<N; i++) printf("%d\n", arr[i]);
	free(arr);
	return 0;
}