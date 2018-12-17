#include <iostream>
#include <vector>
using namespace std;

bool isAllFriend(vector< vector<bool> >& isFriend, vector<int>& list, int dst) {
	bool isOK = true;
	int len = list.size();
	for (int i=0; i<len; i++) {
		if (!isFriend[list[i]][dst]) {
			isOK = false;
			break;
		}
	}
	return isOK;
}

void getList(vector< vector<bool> >& isFriend, vector<int>& list,
			 int T, int K, int len, bool& isFound) {
	if (T == K) {
		isFound = true;
		return;
	}

	int prev = 0;
	if (T>0) prev = list.back();
	for (int i = prev+1; i<=len - K + T + 1; i++) {
		if (isAllFriend(isFriend, list, i)) {
			list.push_back(i);
			getList(isFriend, list, T+1, K, len, isFound);
			if( isFound ) return;
			list.pop_back();
		}
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K, N, F;
	cin >> K >> N >> F;

	vector< vector<bool> > isFriend(N+1);
	for (int i=1; i<=N; i++) isFriend[i].resize(N+1);

	int a, b;
	for (int i=0; i<F; i++) {
		cin >> a >> b;
		isFriend[a][b] = isFriend[b][a] = true;
	}

	vector<int> list;
	bool isFound = false;
	getList(isFriend, list, 0, K, N, isFound);

	if (isFound) {
		for (int i=0; i<K; i++)
			cout << list[i] << '\n';
	}
	else 
		cout << "-1" << '\n';
	return 0;
}