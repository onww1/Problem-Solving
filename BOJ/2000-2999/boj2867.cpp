/*
 *  BOJ 2867. 수열의 값
 *
 *  시간 복잡도 : O(N)
 *  공간 복잡도 : O(N)
 *
 *  수열을 순서대로 보면서 현재 원소보다 앞에 있는 원소들까지의 부분수열에 대해서 
 *  최솟값이 어떤 것이 있고, 그것이 몇개씩인지를 기억하고, 최댓값도 똑같이 기억하게 합니다.
 *  그리고 그러한 값들의 합들을 추적해가면서 조금씩만 변화시킵니다.
 *  저런 최솟값과 최댓값은 스택을 이용하면 갱신하기 쉽습니다. 
 *  그렇게 추적해가면서 변화만 답에 더해주면 답을 구할 수 있습니다.
 */

#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int N, A; 
ll ans, mnS, mxS;
vector <pii> mn, mx;

int main(int argc, char *argv[]) {
    // 처음 값을 받아서 초기화시켜줌.
    scanf("%d %d", &N, &A);
    mn.push_back({A, 1}), mx.push_back({A, 1});
    mnS = mxS = A;

    for (int i = 1, cnt; i < N; ++i) {
        // 다음 원소를 받는다.
        scanf("%d", &A);

        // 최솟값을 가지는 스택을 갱신한다.
        cnt = 1;    // 현재값이 일단 있으므로 1개로 초기화
        while (!mn.empty()) {
            if (mn.back().X >= A) { // 스택의 top 값이 현재값보다 크거나 같으면 꺼내서 합쳐준다.
                mnS -= 1LL * mn.back().X * mn.back().Y; // 이전에 계산된 합에서 이만큼 빼준다.
                cnt += mn.back().Y;
                mn.pop_back();
            } else break;
        }
        mn.push_back({A, cnt}); // 현재값이랑 합쳐진 애들을 스택에 넣어준다.
        mnS += 1LL * A * cnt;   // 현재값에 대한 합을 추가시킨다.

        // 최댓값을 가지는 스택을 갱신한다.
        cnt = 1;    // 현재값이 일단 있으므로 1개로 초기화
        while (!mx.empty()) {
            if (mx.back().X <= A) { // 스택의 top 값이 현재값보다 작거나 같으면 꺼내서 합쳐준다.
                mxS -= 1LL * mx.back().X * mx.back().Y; // 이전에 계산된 합에서 이만큼 빼준다.
                cnt += mx.back().Y;
                mx.pop_back();
            } else break;
        }
        mx.push_back({A, cnt}); // 현재값이랑 합쳐진 애들을 스택에 넣어준다.
        mxS += 1LL * A * cnt;   // 현재값에 대한 합을 추가시킨다.
        
        ans += (mxS - mnS); // 현재 원소에 대한 최댓값의 합과 최솟값의 합의 차이를 답에 더해준다.
    }

    // 답을 출력
    printf("%lld\n", ans);
    return 0;
}