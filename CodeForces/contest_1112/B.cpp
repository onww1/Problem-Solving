#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void calPrime(int N) {
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	prime.push_back(7);

	for (int i=11; i<=N; i+=2) {
		int len = prime.size();
		bool isPrime = true;
		for (int j=0; j < len && prime[j] * prime[j] <= N; j++) {
			if ( i % prime[j] == 0 )
				isPrime = false;
		}
		if (isPrime) 
			prime.push_back(i);
	}
}

int find(int n) {
	int len = prime.size();
	for (int i=0; i<len; i++) {
		if (n % prime[i] == 0)
			return prime[i];
	}
	return -1;
}

int main() {
	int N, cnt = 0;
	cin >> N;

	calPrime(N);
	while (N > 0) {
		int pd = find(N);
		cnt++;
		N -= pd;
	}

	cout << cnt << '\n';
	return 0;
}