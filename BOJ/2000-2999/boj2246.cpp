/*
 *	BOJ 2246. 콘도 선정
 *
 *	시간 복잡도 : O(NlogN)
 *	공가 복잡도 : O(N)
 *
 *	거리에 대해서 정렬을 하고, 맨 처음 항을 먼저 스택에 넣습니다.
 *	그리고 순서대로 보면서 스택의 마지막에 있는 것보다 가격이 작으면 스택에 넣어줍니다.
 *	최종적으로 스택에 있는 원소의 갯수가 답이 됩니다.
 */

#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N;
pii A[MAX];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  for (int i = 0, D, C; i < N; ++i) {
  	scanf("%d %d", &D, &C);
  	A[i] = {D, C};
  }
  sort(A, A + N);	// 정렬
  	
  vector <pii> stack;
  stack.push_back(A[0]);
  	
  for (int i = 1; i < N; ++i) 
  	if (!stack.empty() && stack.back().Y > A[i].Y)
  		stack.push_back(A[i]);
  
  printf("%lu\n", stack.size());
  return 0;
}

