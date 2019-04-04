#include <cstdio>
#include <cstring>

int main(void){
	int n;
	char input[201];
	char arr[20][100];

	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		getchar();
		gets(input);
		int len = strlen(input)/n;
		int k = 0;

		for(int i=0; i<len; i++){
			if(i%2 == 0){
				for(int j=0; j<n; j++){
					arr[i][j] = input[k++];
				}
			}
			else if(i%2 == 1){
				for(int j=n-1; j>=0; j--){
					arr[i][j] = input[k++];
				}
			}
		}

		for(int j=0; j<n; j++){
			for(int i=0; i<len; i++){
				printf("%c", arr[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}