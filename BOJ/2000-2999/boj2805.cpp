#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll getSum(vector<ll>& tree, int H) {
	ll sum = 0LL;
	int len = tree.size();
	for (int i=0; i<len; i++) {
		if (tree[i] > H) 
			sum += (tree[i] - H);
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M;
	cin >> N >> M;

	vector<ll> tree(N);
	for (int i=0; i<N; i++) 
		cin >> tree[i];
	
	int left = -1, right = 1'000'000'001, mid;
	ll sum;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		sum = getSum(tree, mid);
		if (sum == M) break;
		else if (sum < M) right = mid;
		else left = mid;
	}

	if (sum < M) mid -= 1LL;
	cout << mid << '\n';

	return 0;
}