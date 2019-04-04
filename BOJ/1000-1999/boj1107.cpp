#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int abs(int a) { return a < 0 ? -a : a;}

void dfs(vector<int>& btns, vector<int>& nums, int t, int n, int& min) {
	
	if ( t > 0 ) {
		if (t == 1 || nums.back() > 0) {
			int num = 0;
			for (int i=t-1; i>=0; i--)
				num = (num * 10) + nums[i];

			int cnt = abs(num - n) + t;
			min = cnt < min ? cnt : min;
		}
		if (t == 6) return;
	}

	int size = btns.size();
	for (int i=0; i<size; i++) {
		nums.push_back(btns[i]);
		dfs(btns, nums, t + 1, n, min);
		nums.pop_back();
	}
}

int main() {
	int N, M;
	bool btn[10] = { false, };
	cin >> N >> M;

	int in;
	for (int i=0; i<M; i++) {
		cin >> in;
		btn[in] = true;
	}

	vector<int> nums;
	vector<int> btns;
	for (int i=0; i<10; i++)
		if (!btn[i]) btns.push_back(i);

	int min = abs(N - 100);
	dfs(btns, nums, 0, N, min);

	cout << min << '\n';

	return 0;
}