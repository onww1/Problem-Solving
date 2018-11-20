#include <iostream>
#include <vector>
using namespace std;

int N;
int dist[16][16];

int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength) {
	if(path.size() == N)
		return currentLength + dist[path.back()][0];

	int ret = 987654321;
	for (int next = 0; next < N; next++) {
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		int cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = cand < ret ? cand : ret;
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> dist[i][j];
		}
	}

	vector<int> path;
	vector<bool> visited(N);

	path.push_back(0);
	visited[0] = true;
	int min = shortestPath(path, visited, 0);
	cout << min << '\n';

	return 0;
}