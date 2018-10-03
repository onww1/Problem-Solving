#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int X, N;
	vector<int> l;

	while(~scanf("%d", &X)){
		scanf("%d", &N);
		X *= 10000000;
		l.resize(N);

		int L;
		for(int i=0; i<N; i++){
			scanf("%d", &L);
			l[i] = L;
		}

		sort(l.begin(), l.end());
		int head = 0, tail = N-1;
		bool isYes = false;
		while(head < tail){
			if( l[head] + l[tail] == X ){
				isYes = true;
				printf("yes %d %d\n", l[head], l[tail]);
				break;
			}
			else if( l[head] + l[tail] > X ){
				tail--;
			}
			else {
				head++;
			}
		}

		if(!isYes) printf("danger\n");
	}
	
	return 0;
}