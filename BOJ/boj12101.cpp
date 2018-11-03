#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<string> expr;

int N, K;

string itos(int n) {
	if (n == 1) return "1";
	else if(n == 2) return "2";
	else if(n == 3) return "3";
	return NULL;
}

void dfs(int sum) {

	if (sum == N) {
		int len = nums.size();

		string s = itos(nums[0]);
		for (int i=1; i<len; i++) {
			s += "+";
			s += itos(nums[i]);
		}

		expr.push_back(s);
		return;
	}

	for (int i=1; i<=3; i++) {
		if (sum + i <= N) {
			nums.push_back(i);
			dfs(sum + i);
			nums.pop_back();
		}
	}
}

int main() {
	cin >> N >> K;
	dfs(0);
	if (expr.size() < K) cout << "-1\n";
	else cout << expr[K-1] << '\n';

	return 0;
}