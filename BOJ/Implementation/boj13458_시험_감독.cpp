#include <cstdio>
#include <vector>

int main(void){
	int n, b, c, in;
	long long cnt=0;
	std::vector<int> vec;

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &in);
		vec.push_back(in);
	}
	scanf("%d %d", &b, &c);

	for(int i=0; i<n; i++){
		if( vec[i] > 0 ){
			cnt++;
			vec[i] -= b;
		}
		if( vec[i] > 0 ){
			if( vec[i] % c == 0 )
				cnt += (long long)(vec[i]/c);
			else
				cnt += (long long)(vec[i]/c + 1);
		}
	}

	printf("%lld\n", cnt);
	return 0;
}