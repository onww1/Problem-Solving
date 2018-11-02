#include <iostream>
#include <vector>
using namespace std;

struct tower {
	int index;
	int height;
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, x;
	vector<tower> vec;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;

		int len = vec.size();
		if (len == 0) {
			cout << 0 << ' ';
			vec.push_back({i+1, x});
		}
		else {	
			for (int j = len-1; j >= 0; j--) {
				if (vec[j].height > x) {
					cout << vec[j].index << ' ';
					vec.push_back({i+1, x});
					len++;
					break;
				}
				else if (vec[j].height < x) {
					vec.pop_back();
					len--;
				}
			}
			if (len == 0) {
				cout << 0 << ' ';
				vec.push_back({i+1, x});
			}
		}
	}

	cout << '\n';
	return 0;
}