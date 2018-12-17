#include <iostream>
#include <vector>
using namespace std;

struct tree {
	int r, c, age;
};

int N, M, K, A[10][10], F[10][10];
vector<tree> map[10][10];

int move_r[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int move_c[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	return true;
}

// void printCurrentState(int year) {
// 	cout << "Year : " << year << '\n';
// 	cout << "====map state====" << '\n';
// 	for (int i=0; i<N; i++) {
// 		for (int j=0; j<N; j++) {
// 			int len = map[i][j].size();
// 			if (len == 0) cout << "0\t";
// 			else {
// 				cout << len << '(' << map[i][j][0].age;
// 				for (int k=1; k<len; k++)
// 					cout << ',' << map[i][j][k].age;
// 				cout << ')' << "\t";
// 			} 
// 		}
// 		cout <<'\n';
// 	}
// 	cout << "\n\n";

// 	cout << "====F state ====" << '\n';
// 	for (int i=0; i<N; i++) {
// 		for (int j=0; j<N; j++) {
// 			cout << F[i][j] << '\t';
// 		}
// 		cout <<'\n';
// 	}
// 	cout << "\n\n";
// }

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> A[i][j];
			F[i][j] = 5;
			map[i][j] = vector<tree>();
		}
	}

	int r, c, age;
	for (int i=0; i<M; i++) {
		cin >> r >> c >> age;
		map[r-1][c-1].push_back({r-1, c-1, age});
	}

	int year = 0;
	for (; year < K; year++) {
		// printCurrentState(year);

		vector<tree> candidate;

		// spring & summer & winter
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				vector<tree>& cur = map[i][j];
				int len = cur.size();
				for (int k=0; k<len; k++) {
					if (cur[k].age <= F[i][j]) {
						F[i][j] -= cur[k].age;
						cur[k].age += 1;
						if (cur[k].age % 5 == 0) {
							candidate.push_back(cur[k]);
						}
					}
					else {
						for (int l=len-1; l>=k; l--) {
							F[i][j] += (cur.back().age/2);
							cur.pop_back();
						}
						break;
					}
				}
				F[i][j] += A[i][j];
			}
		}

		// fall
		int len = candidate.size();
		for (int i=0; i<len; i++) {
			int r = candidate[i].r;
			int c = candidate[i].c;

			for (int k=0; k<8; k++) {
				int dr = r + move_r[k];
				int dc = c + move_c[k];

				if (check(dr, dc)) {
					map[dr][dc].insert(map[dr][dc].begin(), {dr, dc, 1});
				}
			}
		}
	}
	// printCurrentState(K);

	int cnt = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cnt += map[i][j].size();
		}
	}

	cout << cnt << '\n';

	return 0;
}