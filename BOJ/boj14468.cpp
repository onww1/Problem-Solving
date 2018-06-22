#include <cstdio>
#include <cstring>

int ok[26] = {0, };
int arr[26][2] = {0, };

int check(int a, int b){
	if( (arr[a][0] < arr[b][0] && arr[b][0] < arr[a][1] && arr[a][1] < arr[b][1])
	  ||(arr[b][0] < arr[a][0] && arr[a][0] < arr[b][1] && arr[b][1] < arr[a][1]) )
		return 1;
	return 0;
}

int main(void){
	int cnt = 0;
	char input[53];
	scanf("%s", input);
	for(int i=0; i<52; i++){
		int val = input[i] - 'A';
		if(!ok[val]){
			arr[val][0] = i;
			ok[val] = 1;
		} else arr[val][1] = i;
	}

	for(int i=0; i<25; i++){
		for(int j=i+1; j<26; j++){
			cnt += check(i, j);
		}
	}

	printf("%d\n", cnt);
	return 0;
}