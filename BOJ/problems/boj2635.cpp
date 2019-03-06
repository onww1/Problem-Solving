#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> ans, tmp;
int N, mx;

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = N / 2 + 1; i < N; ++i) {
		tmp.clear();
		tmp.push_back(N);
		tmp.push_back(i);
		int size = 2;
		while (tmp[size - 2] - tmp[size - 1] >= 0) {
			tmp.push_back(tmp[size - 2] - tmp[size - 1]);
			size++;
		}
		if (size > mx) {
			ans = vector<int>(tmp.begin(), tmp.end());
			mx = size;
		}
	}
	printf("%d\n", mx);
	for (int num : ans) printf("%d ", num);
	puts("");
	return 0;
}
