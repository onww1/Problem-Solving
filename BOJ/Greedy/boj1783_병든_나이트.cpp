#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int res = 1;

	if(N == 2){
		res += (M>6?3:(M>4?2:(M>2?1:0)));
	} else if(N > 2){
		if(2 <= M && M <= 4) res += M-1;
		else if(5 <= M && M <= 6) res += 3;
		else if(M >= 7) res += M-3;
	}

	cout << res << '\n';

	return 0;
}