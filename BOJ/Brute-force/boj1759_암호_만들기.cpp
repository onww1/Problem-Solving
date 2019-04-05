#include <cstdio>
#include <algorithm>
using namespace std;

int L, C, cnt=0;
char a[15];
char p[16];

bool isVowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

void dfs(int cur, int t){
	bool vowel = isVowel(a[cur]);
	p[t-1] = a[cur];
	if(vowel) cnt++;

	if(t == L){
		if(cnt >= 1 && L-cnt >= 2)
			printf("%s\n", p);
		if(vowel) cnt--;
		return;
	}

	for(int i=cur+1; i<C; i++){
		dfs(i, t+1);
	}


	if(vowel) cnt--;
}

int main(void){
	scanf("%d %d", &L, &C);
	getchar();
	for(int i=0; i<C; i++){
		a[i] = getchar();
		getchar();
	}

	sort(a, a+C);
	p[L] = '\0';

	for(int i=0; i<=C-L; i++){
		dfs(i, 1);
	}

	return 0;
}