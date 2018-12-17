#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
vector<int> num;

void dfs(int t) {
	if (t == M) {
		cout << vec[0];
		for (int i=1; i<M; i++) 
			cout << ' ' << vec[i];
		cout << '\n';
		return;
	}

	for (int i=0; i<N; i++) {
		vec.push_back(num[i]);
		dfs(t + 1);
		vec.pop_back();
	}
}

int main() {
	cin >> N >> M;
	int cnt = 0, in;

	for (int i=0; i<N; i++) {
		cin >> in;
		num.push_back(in);
	}

	sort(num.begin(), num.end());

	int i=1;
	while (i < N) {
		if (num[i] == num[i-1]) {
			num.erase(num.begin() + i);
			N--;
		}
		else i++;
	}
	
	dfs(0);
	return 0;
}