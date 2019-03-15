/*
 *  BOJ 3006. 터보소트
 *
 *  시간 복잡도 : O(NlogN)
 *  공간 복잡도 : O(N)
 *
 *  각 수의 처음 위치를 저장해주고, 왼쪽으로 이동한 것과 오른쪽으로 이동한 것을 따로 펜윅트리에 갱신합니다.
 *  특정 수의 차례가 왔을 때, 왼쪽과 오른쪽으로 이동했던 것들의 정보를 이용해서 현재 위치를 구하고, 
 *  그것을 이동해야 할 위치의 인덱스와 계산해서 몇 번 swap이 되는지를 계산합니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1e5;
int N, idx[MAX + 1], L[MAX + 1], R[MAX + 1];

// 펜윅트리 update
void update(int *arr, int node, int val) {
    while (node <= N) {
        arr[node] += val;
        node += node & -node;
    }
}

// 펜윅트리 sum 
int sum(int *arr, int node) {
    int sum = 0;
    while (node) {
        sum += arr[node];
        node -= node & -node;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1, A; i <= N; ++i) {
        scanf("%d", &A);
        idx[A] = i; // 각 수의 위치를 저장
    }

    for (int i = 1, l = 1, r = N; i <= N; ++i) {
        if (i % 2) {    // 홀수번째일 때
            printf("%d\n", idx[l] - sum(R, idx[l] - 1) + sum(L, N) - sum(L, idx[l]) - l);
            update(L, idx[l], 1);
            l++;
        } else {    // 짝수번째 일떄
            printf("%d\n", r - idx[r] + sum(R, idx[r] - 1) - sum(L, N) + sum(L, idx[r]));
            update(R, idx[r], 1);
            r--;
        }
    }

    return 0;
}