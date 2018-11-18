#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct point {
	int r, c, d;
};

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c, int R, int C) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

void solve(vector< vector<int> >& dist, vector<int>& list, int T, int M, int& min) {
	if (T == M) {
		int numOfHouses = dist.size();

		int sum = 0;
		for (int i=0; i<numOfHouses; i++) {
			int local_min = 987654321;
			for (int j=0; j<M; j++) {
				local_min = dist[i][list[j]] < local_min ? dist[i][list[j]] : local_min;
			}
			sum += local_min;
		}
		min = sum < min ? sum : min;
		return;
	}

	int prev = -1, numOfChickens = dist[0].size();
	if (T > 0) prev = list.back();

	for (int i=prev+1; i<=numOfChickens-M+T; i++) {
		list.push_back(i);
		solve(dist, list, T+1, M, min);
		list.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, map[50][50];
	vector<point> chickens;
	int numOfHouses = 0, numOfChickens = 0;
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				numOfHouses++;
				map[i][j] = numOfHouses;
			}
			else if (map[i][j] == 2) {
				numOfChickens++;
				map[i][j] = -numOfChickens;
				chickens.push_back({i, j, 0});
			}
		}
	}

	vector< vector<int> > dist(numOfHouses);
	for (int i=0; i<numOfHouses; i++) dist[i].resize(numOfChickens);

	for (int i=0; i<numOfChickens; i++) {
		int cnt = 0;
		queue<point> q;
		bool visited[50][50] = { false, };
		q.push(chickens[i]);
		visited[q.front().r][q.front().c] = true;

		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int d = q.front().d;
			q.pop();

			for (int k=0; k<4; k++) {
				int dr = r + move_r[k];
				int dc = c + move_c[k];

				if(check(dr, dc, N, N) && !visited[dr][dc]) {
					if (map[dr][dc] > 0) {
						dist[map[dr][dc]-1][i] = d+1;
					}
					visited[dr][dc] = true;
					q.push({dr, dc, d+1});
				}
			}
		}
	}

	int min = 987654321;
	vector<int> list;
	solve(dist, list, 0, M, min);

	cout << min << '\n';

	return 0;
}