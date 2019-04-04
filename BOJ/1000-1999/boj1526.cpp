#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N, mx;
queue <int> q;
int main() {
	scanf("%d", &N);
	q.push(0);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		mx = max(mx, cur);
		if (cur * 10 + 7 <= N) q.push(cur * 10 + 7);
		if (cur * 10 + 4 <= N) q.push(cur * 10 + 4);
	}
	return !printf("%d\n", mx);
}