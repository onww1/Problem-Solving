#include <stdio.h>
#include <string.h>

int main(void){
	int N, i, j, k;

	scanf("%d", &N);
	for(i = 0; i < N; i++){
		char *arr;
		int n;

		printf("in1\n");
		scanf("%s", arr);
		printf("----\n");

		n = strlen(arr);
		printf("in2\n");
		printf("%d\n", n);

		for(j=0; j<n; j++)
			printf("%c ", arr[j]);

		//int *numarr = NULL;

		for(j=0; j<n; j++)
			printf("%c ", arr[j]);
	}

	return 0;
}