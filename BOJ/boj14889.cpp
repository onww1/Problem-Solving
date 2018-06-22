#include <cstdio>
#include <vector>

int N, sum1, sum2, minVal = 1e9;
int arr[21][21] = {0, };
std::vector<int> vec1;
std::vector<int> vec2;

int abs(int a){ return a>0?a:-a;}

void dfs(int cnt){
	if(cnt == N/2){
		vec2.clear();
		for(int i=1, j=0; i<=N; i++){
			if(i == vec1[j]) j++;
			else vec2.push_back(i);
		}
		
		sum1 = 0; sum2 = 0;
		for(int i=0; i<N/2; i++){
			for(int j=0; j<N/2; j++){
				sum1 += arr[vec1[i]][vec1[j]];
				sum2 += arr[vec2[i]][vec2[j]];
			}
		}
		int val = abs(sum1 - sum2);
		if(val < minVal) minVal = val;
	} else {
		for(int i=vec1[cnt-1]+1; i<=N-N/2+cnt+1; i++){
			vec1.push_back(i);
			dfs(cnt+1);
			vec1.pop_back();
		}
	}
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	vec1.push_back(1);
	dfs(1);
	printf("%d\n", minVal);
	return 0;
}