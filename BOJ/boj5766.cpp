#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ranking {
	int id, num;
};

bool cmp(ranking& a, ranking& b) {
	if (a.num == b.num) return a.id < b.id;
	return a.num > b.num;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	while (1) {
		cin >> N >> M;
		if (!N && !M) break;

		vector<ranking> vec(10001);
		for (int i=1; i<=10000; i++)
			vec[i].id = i;

		int id;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cin >> id;
				vec[id].num++;
			}
		}

		sort(vec.begin(), vec.end(), cmp);
		int num = vec[1].num;
		cout << vec[1].id;
		int idx = 2;
		while (vec[idx].num == num) {
			cout << ' ' << vec[idx].id;
			idx++;
		}
		cout << '\n';
	}
	return 0;
}