// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
// 	cin.tie(NULL);
// 	ios_base::sync_with_stdio(false);
	
// 	int N;
// 	cin >> N;
	
// 	int A[1000];
// 	for(int i=0; i<N; i++)
// 		cin >> A[i];
	
// 	int dp[1000] = {0, };
// 	dp[0] = 1;
	
// 	int global_max = dp[0];
// 	for(int i=1; i<N; i++){
// 		int max = 0;
// 		for(int j=i-1; j>=0; j--){
// 			if(A[i] > A[j] && max < dp[j]) max = dp[j];	
// 		}
// 		dp[i] = max + 1;
// 		global_max = dp[i] > global_max ? dp[i] : global_max;
// 	}
	
// 	cout << global_max << '\n';
// 	return 0;	
// }

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> lis;
int main() {
    int n, a, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a);
        auto it = lower_bound(lis.begin(), lis.end(), a);
        if (it == lis.end()) lis.push_back(a);
        else *it = a;
    }
    return !printf("%lu\n", lis.size());
}