#include <cstdio>
#include <cstring>
#include <queue>

int arr[100001] = {0, };
bool visited[100001] = {0, };
int main(void){
	int n, k;
	scanf("%d %d", &n, &k);

	if(k<n){
		printf("%d\n", n-k);
	} else {
		std::queue<int> q;
		q.push(n);

		while(!q.empty()){
			int cur = q.front();
			q.pop();

			if(cur==k) break;

			if(cur-1 >= 0 && !visited[cur-1]){
				arr[cur-1] = arr[cur] + 1;
				visited[cur-1] = 1;
				q.push(cur-1);
			}
			if(cur+1 <= 100000 && !visited[cur+1]){
				arr[cur+1] = arr[cur] + 1;
				visited[cur+1] = 1;
				q.push(cur+1);
			}
			if(2*cur <= 100000 && !visited[cur*2]){
				arr[cur*2] = arr[cur] + 1;
				visited[2*cur] = 1;
				q.push(2*cur);
			}
		}
		printf("%d\n", arr[k]);
	}

	return 0;
}