#include <cstdio>
#include <cstring>

int binarysearch(char* input, int start, int end){
	int mid = (start+end)/2;
	int left, right;
	if('a' <= input[mid] && input[mid] <= 'z'){
		while(1){
			if(mid > 0 && 'a' <= input[mid-1] && input[mid-1] <= 'z') mid--;
			else break;
		}
		return mid;
	} else if( start >= end ) return -1;
	if((left = binarysearch(input, start, mid)) != -1) return left;
	if((right = binarysearch(input, mid+1, end)) != -1) return right;
	return -1;
}

int lastIndex(char* input, int startIndex){
	int index = startIndex;
	int len = strlen(input);
	while(index < len - 1 && 'a' <= input[index+1] && input[index+1] <= 'z')
		index++;
	return index;
}

int main(void){
	int t, n, len, engIdx, lastIdx;
	char input[1100];

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		getchar();
		gets(input);
		len = strlen(input);
		engIdx = binarysearch(input, 0, len-1);
		if(engIdx == -1) {
			printf("%s\n", input);
			continue;
		}
		lastIdx = lastIndex(input, engIdx);
		for(int i=lastIdx+2; i<len; i++){
			printf("%c", input[i]);
		}
		if(lastIdx != len-1) printf(" ");
		for(int i=engIdx; i<=lastIdx; i++){
			printf("%c", input[i]);
		}
		printf(" ");
		engIdx--;
		for(int i=0; i<engIdx; i++){
			printf("%c", input[i]);
		}
		printf("\n");
	}
	return 0;
}