#include <iostream>
#include <vector>
using namespace std;

int N, M;
long long cnt = 0;
bool isBad[200][200] = {false, };

vector<int> v;

void dfs(int t) {
	
	if (t == 3) {
		cnt++;
		return;
	}

	bool isOK = true;
	for (int i=t?v[t-1]+1:0; i<N-2+t; i++) {
		isOK = true;
		for (int j=0; j<t; j++) {
			if ( isBad[v[j]][i] ) {
				isOK = false;
				break;
			}
		}
		if (isOK) {
			v.push_back(i);
			dfs(t+1);
			v.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		isBad[a-1][b-1] = isBad[b-1][a-1] = true;
	}

	dfs(0);
	cout << cnt << '\n';
	return 0;
}