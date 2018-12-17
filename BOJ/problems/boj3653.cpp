#include <cstdio>
#include <vector>

int main(void){
	int t, n, m, in;
	int num[100001];
	std::vector<int> vec(100000);

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++){
			num[i] = i-1;
			vec.push_back(n-i+1);
		}

		while(m--){
			scanf("%d", &in);
			if(m > 0) printf("%d ", num[in]);
			else printf("%d\n", num[in]);

			for(auto it = vec.begin()+n-num[in]; it != vec.end(); it++){
				num[*it]++;
			}
			vec.erase(vec.begin()+n-num[in]-1);
			vec.push_back(in);
			num[in] = 0;
		}

		vec.erase(vec.begin(), vec.end());
	}
	
	return 0;
}