#include <cstdio>

int max(int a, int b, int c){
	int max = a;
	if(b>max) max = b;
	if(c>max) max = c;
	return max;
}

int main(void){
	int N, M, arr[1000][1000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &arr[i][j]);

	for(int i=N-2; i>=0; i--)
		arr[i][M-1] += arr[i+1][M-1];
	for(int j=M-2; j>=0; j--)
		arr[N-1][j] += arr[N-1][j+1];
	for(int i=N-2; i>=0; i--){
		for(int j=M-2; j>=0; j--){
			arr[i][j] += max(arr[i+1][j], arr[i][j+1], arr[i+1][j+1]);
		}
	}

	printf("%d\n", arr[0][0]);
	return 0;
}