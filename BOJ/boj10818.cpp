#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	vector<int> vec;

	cin >> N;
	vec.resize(N);

	for (int i=0; i<N; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	cout << vec[0] << ' ' << vec[N-1] << '\n';
	return 0;
}