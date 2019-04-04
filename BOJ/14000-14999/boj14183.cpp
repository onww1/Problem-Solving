#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int L, N;
	while (1) {
		cin >> L >> N;
		if (!L && !N) break;

		vector<int> org(L);
		int cnt = 0;

		for (int i=0; i<L; i++) 
			cin >> org[i];

		while (N--) {
			bool isOK = true;
			int in;
			for (int i=0; i<L; i++) {
				cin >> in;
				if (org[i] < in) isOK = false;
			}
			if (isOK) cnt++;
		}

		cout << cnt << '\n';
	}
	return 0;
}