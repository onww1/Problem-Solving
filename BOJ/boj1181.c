#include <stdio.h>
#include <string.h>
const int A = 20000;
const int B = 51;

void merge(char arr[A][B], int s, int m, int t){
	char tmp[A][B];
	int a = s, b = m+1, c = 0;
	while(a <= m && b <= t){
		int len1 = strlen(arr[a]), len2 = strlen(arr[b]);
		if(len1 < len2){
			strcpy(tmp[c], arr[a]);
			c++; a++;
		} else if(len1 > len2){
			strcpy(tmp[c], arr[b]);
			c++; b++;
		} else if(len1 == len2){
			int cmp = strcmp(arr[a], arr[b]);
			if(cmp > 0){
				strcpy(tmp[c], arr[b]);
				c++; b++;
			} else if(cmp < 0){
				strcpy(tmp[c], arr[a]);
				c++; a++;
			} else{
				strcpy(tmp[c], arr[a]);
				c++; a++;
				strcpy(tmp[c], arr[b]);
				c++; b++;
			}
		}
	}
	while(a <= m){
		strcpy(tmp[c], arr[a]);
		c++; a++;
	}
	while(b <= t){
		strcpy(tmp[c], arr[b]);
		c++; b++;
	}
	for(int j=s, k=0; k<c; j++, k++) strcpy(arr[j], tmp[k]);
	return;
}

void mergesort(char arr[A][B], int s, int t){
	if(s==t) return;
	int m = (s+t)/2;
	mergesort(arr, s, m);
	mergesort(arr, m+1, t);
	merge(arr, s, m, t);
	return;
}

int main(void){
	char input[A][B];
	char prev[51] = "\0";
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%s", input[i]);
	mergesort(input, 0, n-1);
	for(int i=0; i<n; i++){
		if(strcmp(prev, input[i]) != 0){
			strcpy(prev, input[i]);
			printf("%s\n", input[i]);
		}
	}
	return 0;
}