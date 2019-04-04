#include <cstdio>
using namespace std;

int n;
bool visited[9] = {false, };
char p[16];

void dfs(int t){
	if(t == n){
		printf("%s\n", p);
		return ;
	}

	for(int i=1; i<=n; i++){
		if(!visited[i]){
			visited[i] = true;
			p[2*t] = i + '0';
			dfs(t+1);
			visited[i] = false;
		}
	}
}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<2*n; i++) p[i] = ' ';
	p[2*n - 1] = '\0';

	dfs(0);

	return 0;
}