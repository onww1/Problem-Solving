#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	vector<int> vec(5);

	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<5; j++) {
			cin >> vec[j];
		}
		sort(vec.begin(), vec.end());
		cout << "Case #" << (i+1) << ": " << vec[4] << '\n';
	}
	return 0;
}