#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N, cnt, A[1000]; 
	bool visited[1000];
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i=0; i<N; ++i) {
			cin >> A[i];
			A[i]--;
		}
		memset(visited, false, N);

		cnt = 0;
		queue<int> q;
		for (int i=0; i<N; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
				cnt++;
				while (!q.empty()) {
					int top = q.front();
					q.pop();

					if (!visited[A[top]]) {
						visited[A[top]] = true;
						q.push(A[top]);
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}