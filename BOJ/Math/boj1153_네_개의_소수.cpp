#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1e6;
int N;
bool nonPrime[MAX + 1] = {true, true, };

int main(int argc, char *argv[]) {
    for (int i = 2; i * i <= MAX; ++i) 
        if (!nonPrime[i]) 
            for (int j = i * i; j <= MAX; j += i) 
                nonPrime[j] = true;

    scanf("%d", &N);
    if (N < 8) return !printf("-1\n");

    vector <int> prime;
    if (N % 2) {
        prime.push_back(2);
        prime.push_back(3);
        N -= 5;
    } else {
        prime.push_back(2);
        prime.push_back(2);
        N -= 4;
    }

    for (int i = 2; i <= N / 2; ++i) {
        if (!nonPrime[i] && !nonPrime[N - i]) {
            prime.push_back(i);
            prime.push_back(N - i);
            break;
        }
    }

    sort(prime.begin(), prime.end());
    for (int pr : prime) printf("%d ", pr); puts("");

    return 0;
}