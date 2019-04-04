#include <cstdio>
#include <algorithm>
using namespace std;

int N, S, P;
int r[51];

int main(){
	scanf("%d %d %d", &N, &S, &P);
	for(int i=0; i<N; i++){
		scanf("%d", &r[i]);
	}

	int idx, ranking = -1;
	for(idx=0; idx<N; idx++){
		if(r[idx] == S){
			if(ranking == -1) ranking = idx+1;
		}
		else if(r[idx] < S) break;
	}

	if(ranking == -1) ranking = idx+1;

	if(idx < P) printf("%d\n", ranking);
	else printf("-1\n");
	return 0;
}