#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
int cnt = 0;

void hanoi(int n, int from, int mid, int to) {
	if( n == 0 ) return;
	hanoi(n-1, from, to, mid);
	result.push_back(from);
	result.push_back(to);
	cnt++;
	hanoi(n-1, mid, from, to);
}

int main() {
	int N;
	cin >> N;

	hanoi(N, 1, 2, 3);
	cout << cnt << '\n';
	int len = result.size();
	for (int i = 0; i < len; i+=2) {
		cout << result[i] << ' ' << result[i+1] << '\n';
	}

	return 0;
}