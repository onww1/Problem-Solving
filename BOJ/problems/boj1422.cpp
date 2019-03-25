#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct str {
    char num[20];
    int len;
};

int K, N, LMX;
str nums[1005];

bool cmp(str &A, str &B) {
    int LIM = A.len + B.len;
    for (int i = 0; i < LIM; ++i) if (A.num[i % A.len] != B.num[i % B.len]) return B.num[i % B.len] - A.num[i % A.len] < 0;
    return A.len > B.len;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; ++i) {
        scanf(" %s", nums[i].num);
        nums[i].len = 0;
        for (; nums[i].num[nums[i].len]; nums[i].len++);
        LMX = max(LMX, nums[i].len);
    }

    sort(nums, nums + K, cmp);

    for (int i = 0, f = 1; i < K; ++i) {
        printf("%s", nums[i].num);
        if (f && nums[i].len == LMX) {
            f = 0;
            while (N > K) printf("%s", nums[i].num), N--;
        }
    }
    puts("");

    return 0;
}