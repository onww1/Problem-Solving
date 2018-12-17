#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct point {
	int r, c;
};

bool isComplete(vector< vector<bool> >& ladder) {
	int H = ladder.size();
	int N = ladder[0].size();

	bool isValid = true;
	for (int i=0; i<N; i++) {
		int c = i;
		int r = 0;

		while (r < H) {
			if (c < N-1 && ladder[r][c]) {
				c++;
			}
			else if (c > 0 && ladder[r][c-1]) {
				c--;
			}
			r++;
		}
		if (c != i) {
			isValid = false;
			break;
		}
	}
	return isValid;
}

bool canIPutBridge(vector< vector<bool> >& ladder, int r, int c) {
	if (ladder[r][c]) return false;
	else if (c > 0 && ladder[r][c-1]) return false;
	else if (c < ladder[0].size() - 1 && ladder[r][c+1]) return false;
	return true;
}

void solve(vector< vector<bool> >& ladder, vector<point>& selected, int T, int& min) {

	if (isComplete(ladder)) {
		min = T < min ? T : min;
		return;
	}

	if (T == 3) return;

	int prev_r = 0, prev_c = -1;
	if (T > 0) {
		prev_r = selected.back().r;
		prev_c = selected.back().c;
	}

	int H = ladder.size();
	int N = ladder[0].size();

	for (int i=prev_c+1; i<N-1; i++) {
		if (canIPutBridge(ladder, prev_r, i)) {
			ladder[prev_r][i] = true;
			selected.push_back({prev_r, i});
			solve(ladder, selected, T+1, min);
			ladder[prev_r][i] = false;
			selected.pop_back();
		}
	}

	for (int j=prev_r + 1; j<H; j++) {
		for (int i=0; i<N-1; i++) {
			if (canIPutBridge(ladder, j, i)) {
				ladder[j][i] = true;
				selected.push_back({j, i});
				solve(ladder, selected, T+1, min);
				ladder[j][i] = false;
				selected.pop_back();
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, H;
	vector< vector<bool> > ladder;

	cin >> N >> M >> H;
	ladder.resize(H);
	for (int i=0; i<H; i++) 
		ladder[i].resize(N);

	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		ladder[a-1][b-1] = true;
	}

	int min = INF;
	vector<point> selected;
	solve(ladder, selected, 0, min);

	if (min == INF) cout << "-1" << '\n';
	else cout << min << '\n';

	return 0;
}