#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b;}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> vec(N);

	for (int i=0; i<N; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i=0; i<N; i++) {
		cout << vec[i] << '\n';
	}
	return 0;
}