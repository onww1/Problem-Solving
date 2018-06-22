#include <cstdio>
#include <cstring>
#include <queue>

int arr[100001] = {0, };

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	memset(arr, 200000, 400004);

	std::queue<int> q;
	q.push(n);
	arr[n] = 0;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(cur-1 >= 0 && arr[cur-1] > arr[cur] + 1){
			arr[cur-1] = arr[cur]+1;
			q.push(cur-1);
		}
		if(cur+1 <= 100000 && arr[cur+1] > arr[cur] + 1){
			arr[cur+1] = arr[cur]+1;
			if(cur < k) q.push(cur+1);
		}
		if(cur*2 <= 100000 && arr[cur*2] > arr[cur] + 1){
			arr[cur*2] = arr[cur]+1;
			if(cur < k) q.push(cur*2);
		}
	}

	printf("%d\n", arr[k]);

	return 0;
}