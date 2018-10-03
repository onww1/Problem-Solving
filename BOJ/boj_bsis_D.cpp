#include <cstdio>
using namespace std;

int main(void)
{
	int k;
	scanf("%d", &k);

	bool dp[10000001];
	dp[0] = dp[1] = true;

	for(int i=2; i*i<=10000000; i++)
	{
		if(!dp[i])
		{
			for(int j=i; i*j <= 10000000; j++)
				dp[i * j] = true;
		}
	}

	int cnt = 0;
	for(int i=1; i<10000001; i++)
	{
		if(!dp[i])
		{
			cnt++;
			if(cnt == k)
			{
				printf("%d", i);
				break;
			}
		}
	}

	return 0;
}

// long long prime_number(int k, vector<long long> &prime)
// {
// 	if(prime[k]) return prime[k];
// 	else
// 	{
// 		int loop = 1;

// 		if( prime[k-1] == 0 )
// 			prime[k-1] = prime_number(k-1, prime);

// 		long long ret = prime[k-1];

// 		while(loop)
// 		{
// 			ret+=2;
// 			loop = 0;

// 			for(int i=1; prime[i] * prime[i] <= ret; i++)
// 			{
// 				if(ret % prime[i] == 0)
// 					loop = 1;
// 				if(loop) break;
// 			}	
// 		}

// 		return ret;
// 	}
// }

// int main(void)
// {
// 	int k;
// 	long long res;

// 	scanf("%d", &k);

// 	vector<long long> prime(k+1);
// 	for(int i=0; i<=k; i++)
// 		prime[i] = 0;
// 	prime[1] = 2;
// 	prime[2] = 3;
// 	prime[3] = 5;

// 	res = prime_number(k, prime);
// 	printf("%lld\n", res);

// 	return 0;
// }