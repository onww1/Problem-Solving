#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int T, N;
string numbers[10000];

bool compareString(string a, string b){
	int len1 = a.length();
	int len2 = b.length();
	int len = len1<len2?len1:len2;
	for(int i=0; i<len; i++){
		if(a[i] < b[i]) return true;
		else if(a[i] > b[i]) return false;
	}
	return len1<len2;
}

bool isPrefix(int a, int b){
	int len = numbers[a].length();
	for(int i=0; i<len; i++){
		if(numbers[a][i] != numbers[b][i]) return false;
	}
	return true;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		getchar();
		for(int i=0; i<N; i++){
			getline(cin, numbers[i]);
		}

		sort(numbers, numbers+N, compareString);

		bool isYes = true;
		for(int i=1; i<N && isYes; i++){
			for(int j=0; j<i && isYes; j++){
				if(isPrefix(j, i)){
					printf("NO\n");
					isYes = false;
				}
			}
		}

		if(isYes){
			printf("YES\n");
		}
	}

	return 0;
}