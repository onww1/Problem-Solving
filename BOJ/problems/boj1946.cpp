#include <cstdio>
#include <algorithm>
using namespace std;

struct man
{
	int a, b;
};

bool compareA(man a, man b) { return a.a<b.a; }

int main(){
	int T, N;
	man mans[100000];

	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		int a, b;
		for(int i=0; i<N; i++){
			scanf("%d %d", &a, &b);
			mans[i] = {a, b};
		}

		sort(mans, mans+N, compareA);

		int cnt = 1;
		int min = mans[0].b;
		for(int i=1; i<N; i++){
			if(mans[i].b < min){
				cnt++;
				min = mans[i].b;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}