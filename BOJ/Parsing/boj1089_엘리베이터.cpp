/*
 *  BOJ 1089. 엘리베이터
 * 
 *  정말 맘에 안드는 구데기 코드네요!!! (이전 버전)
 *  딱히 숫자를 어떻게 커버해야 할 지 모르겠어서 안되는 것만 걸러내는 식으로 했습니다.
 *  전체 돌면서 #을 만났는데 그 자리에 #이 있을 경우 될 수 없는 수들을 체크하고,
 *  뒤에서 되는 수들에 대해서 모든 경우의 수의 합을 구하고 그것을 전체 경우의 수로 나누어서
 *  평균을 구했습니다.
 *  그리고 만약 한 자릿수에 대해서 되는 수가 하나도 없다면 바로 -1을 출력하도록 짰습니다.
 * 
 *  +) 안되는 수를 찾는 과정에 대한 코드를 좀 바꾸었습니다.
 *  밑에 주석 달린 코드가 이전에 짠 것이고, 주석이 달리지 않은 것이 새로 짠 것입니다.
 */

#include <cstdio>
using namespace std;
typedef long long ll;

bool invalid[10][10]; // 안되는 수들을 체크하는 배열
char in[5][40], org[10][5][4] = {
                                  {"###", "#.#", "#.#", "#.#", "###"},
                                  {"..#", "..#", "..#", "..#", "..#"},
                                  {"###", "..#", "###", "#..", "###"},
                                  {"###", "..#", "###", "..#", "###"},
                                  {"#.#", "#.#", "###", "..#", "..#"},
                                  {"###", "#..", "###", "..#", "###"},
                                  {"###", "#..", "###", "#.#", "###"},
                                  {"###", "..#", "..#", "..#", "..#"},
                                  {"###", "#.#", "###", "#.#", "###"},
                                  {"###", "#.#", "###", "..#", "###"}
                                }; 

int main(int argc, char *argv[]) {
  int n, i, j, k, l;
  scanf("%d", &n);
  for (i = 0; i < 5; ++i) scanf(" %s", in[i]);
  for (i = 0; i < n; ++i)  // n개의 수에 대해서 확인
    for (j = 0; j < 5; ++j)  // 5개의 행을 확인
      for (k = 4 * i; k < 4 * i + 3; ++k) // 각 자리마다 3열이니까 그것들을 확인
        if (in[j][k] == '#') // 만약 그 자리에 #이 있고,
          for (l = 0; l < 10; ++l)  // 숫자 표현에서는 .이 필요하다면 그 숫자는 표현할 수 없음.
            if (org[l][j][k - 4 * i] == '.') 
              invalid[i][l] = true;
          
  bool flag = false;
  int cnt[10] = {0}, sum[10] = {0};
  ll mul = 1LL, tot = 0LL;
  for (i = 0; i < n; ++i) {
    flag = false; // 이 자릿수에 대해서 되는 수가 있는지 확인하는 flag
    for (j = 0; j < 10; ++j) 
      if (!invalid[i][j]) {
        flag = true;
        sum[i] += j;
        cnt[i]++;
      }
    if (!flag) return !printf("-1\n");  // 되는 수가 없으면 -1 출력
    mul *= (ll)cnt[i];  // 전체 경우의 수 계산
  }

  for (i = 0; i < n; ++i) {
    // 각 자리에 대해서 그 자릿수의 합과 나머지 자릿수에 대한 경우의 수를 곱해서 더함.
    tot = tot * 10LL + (ll)sum[i] * (mul / cnt[i]); 
  }

  // 전체 합에 대해서 전체 경우의 수를 나누어 평균을 구하고 출력.
  return !printf("%lf\n", (double)tot / mul);
}


// #include <cstdio>
// #include <vector>
// using namespace std;
// typedef long long ll;

// char in[5][40]; 
// bool invalid[10][10]; // 안되는 수들을 체크하는 배열
// int main(int argc, char *argv[]) {
//   int n, i, j, k;
//   scanf("%d", &n);
//   for (i = 0; i < 5; ++i) scanf(" %s", in[i]);
//   for (i = 0; i < n; ++i) {
//     for (j = 0; j < 5; ++j) {
//       for (k = 4 * i; k < 4 * i + 3; ++k) {
//         if (in[j][k] == '#') {  // #을 만났을 때,
//           if (k % 4 == 1 && j != 0 && j != 4) // 0이 될 수 없는 상황
//             invalid[i][0] = true;
//           if (k % 4 == 0 || k % 4 == 1) // 1이 될 수 없는 상황
//             invalid[i][1] = true;
//           if ((j == 1 && k % 4 != 2) || (j == 3 && k % 4 != 0)) // 2가 될 수 없는 상황
//             invalid[i][2] = true;
//           if ((j == 1 || j == 3) && k % 4 != 2) // 3이 될 수 없는 상황
//             invalid[i][3] = true;
//           if ((k % 4 == 1 && j != 2) || (k % 4 == 0 && (j == 3 || j == 4))) // 4가 될 수 없는 상황
//             invalid[i][4] = true;
//           if ((j == 1 && k % 4 != 0) || (j == 3 && k % 4 != 2)) // 5가 될 수 없는 상황
//             invalid[i][5] = true;
//           if ((j == 1 && k % 4 != 0) || (j == 3 && k % 4 == 1)) // 6이 될 수 없는 상황
//             invalid[i][6] = true;
//           if (j != 0 && k % 4 != 2) // 7이 될 수 없는 상황
//             invalid[i][7] = true;
//           if (k % 4 == 1 && (j == 1 || j == 3)) // 8이 될 수 없는 상황
//             invalid[i][8] = true;
//           if ((j == 1 && k % 4 == 1) || (j == 3 && k % 4 != 2)) // 9가 될 수 없는 상황
//             invalid[i][9] = true;
//         }
//       }
//     }
//   }

//   bool flag = false;
//   int cnt[10] = {0}, sum[10] = {0};
//   ll mul = 1LL, tot = 0LL;
//   for (i = 0; i < n; ++i) {
//     flag = false; // 이 자릿수에 대해서 되는 수가 있는지 확인하는 flag
//     for (j = 0; j < 10; ++j) 
//       if (!invalid[i][j]) {
//         flag = true;
//         sum[i] += j;
//         cnt[i]++;
//       }
//     if (!flag) return !printf("-1\n");  // 되는 수가 없으면 -1 출력
//     mul *= (ll)cnt[i];  // 전체 경우의 수 계산
//   }

//   for (i = 0; i < n; ++i) {
//     // 각 자리에 대해서 그 자릿수의 합과 나머지 자릿수에 대한 경우의 수를 곱해서 더함.
//     tot = tot * 10LL + (ll)sum[i] * (mul / cnt[i]); 
//   }

//   // 전체 합에 대해서 전체 경우의 수를 나누어 평균을 구하고 출력.
//   return !printf("%lf\n", (double)tot / mul);
// }
