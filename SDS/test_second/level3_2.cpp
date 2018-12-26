#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int pow(int base, int exp);

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T, N, R, P1, P2, T1, T2, answer;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> R >> N;
    answer = INF;
    vector< vector<int> > nodes(2 * N + 1, vector<int>(pow(3, N), INF));
    vector<int> pos(2 * N + 1);
    
    for (int i = 0; i < N; ++i) {
      cin >> P1 >> P2 >> T1 >> T2;
      pos.push_back(P1);
      pos.push_back(P2);
    }

  }

  return 0;
}

int pow(int base, int exp) {
  int res = base, cnt = 1;
  for (; cnt * cnt <= exp; ++cnt) res *= res;
  for (; cnt <= exp; ++cnt) res *= base;
  return res;
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #define INF 987654321
// using namespace std;

// struct task {
//   int p, s, e, i;
// };

// bool cmp(task a, task b) {
//   if (a.e == b.e) return a.s < b.s;
//   return a.e < b.e;
// }

// int T, N, R, P1, P2, T1, T2, answer;
// vector<task> tasks;
// vector<int> status;

// int get_abs(int a);
// int get_min(int a, int b);
// int get_max(int a, int b);
// void solve(int cur, int time, int prior);

// int main(int argc, char *argv[]) {
//   cin.tie(0);
//   ios_base::sync_with_stdio(false);

//   cin >> T;
//   for (int test_case = 1; test_case <= T; ++test_case) {
//     cin >> R >> N;
//     answer = INF;
//     tasks.resize(2 * N);
//     status.clear();
//     status.resize(2 * N, 0);
  
//     for (int i = 0; i < N; ++i) {
//       cin >> P1 >> P2 >> T1 >> T2;
//       tasks[i] = {P1, T1, T2 - get_abs(P2 - P1), i};
//       tasks[i + N] = {P2, T1 + get_abs(P2 - P1), T2, i+N};
//     }
//     sort(tasks.begin(), tasks.end(), cmp);
//     solve(R, 0, 0); 

//     cout << '#' << test_case << ' ' << (answer == INF ? -1 : answer) << '\n';
//   }

//   return 0;
// }

// void solve(int cur, int time, int prior) {
//   cout << "prior : " << prior << '\n';
//   cout << "cur : " << cur << ", time : " << time << '\n';

//   if (time >= answer) return;
//   if (prior == 2*N) {
//     answer = time < answer ? time : answer;
//     return;
//   }

//   bool hasRest = false;
//   for (int i = 0; i < 2 * N; ++i) {
//     if (status[tasks[i].i]) continue;
//     if (hasRest && tasks[i].s > tasks[i-1].e) return;
//     if (tasks[i].i >= N && !status[tasks[i].i - N]) return;
//     if (time + get_abs(cur - tasks[i].p) > tasks[i].e) return;

//     cout << "task " << tasks[i].i << " >> p : " << tasks[i].p << ", s : " << tasks[i].s << ", e : " << tasks[i].e << '\n';
//     status[tasks[i].i] = 1;
//     solve(tasks[i].p, get_max(tasks[i].s, time + get_abs(cur - tasks[i].p)), prior + 1);
//     status[tasks[i].i] = 0;

//     hasRest = true;
//   }
// }

// int get_abs(int a) { return a < 0 ? -a : a; }
// int get_min(int a, int b) { return a < b ? a : b; }
// int get_max(int a, int b) { return a > b ? a : b; }

// // #include <iostream>
// // #include <algorithm>
// // #include <vector>
// // #define INF 987654321
// // using namespace std;

// // struct task {
// //   int p, s, e, i;
// // };

// // bool cmp(task a, task b) {
// //   if (a.s == b.s) return a.e < b.e;
// //   return a.s < b.s;
// // }

// // int T, N, R, P1, P2, T1, T2, answer;
// // vector<task> tasks;
// // vector<int> status;

// // int get_abs(int a);
// // int get_min(int a, int b);
// // int get_max(int a, int b);
// // void solve(int cur, int time, int prior);

// // int main(int argc, char *argv[]) {
// //   cin.tie(0);
// //   ios_base::sync_with_stdio(false);

// //   cin >> T;
// //   for (int test_case = 1; test_case <= T; ++test_case) {
// //     cin >> R >> N;
// //     answer = INF;
// //     tasks.resize(2 * N);
// //     status.clear();
// //     status.resize(2 * N, 0);
    
    
// //     int cur = R, time = 0;
// //     for (int i = 0; i < N; ++i) {
// //       cin >> P1 >> P2 >> T1 >> T2;
// //       tasks[i] = {P1, T1, T2 - get_abs(P2 - P1), i};
// //       tasks[i + N] = {P2, T1 + get_abs(P2 - P1), T2, i+N};
// //     }
// //     sort(tasks.begin(), tasks.end(), cmp);
// //     solve(cur, time, 0); 

// //     cout << '#' << test_case << ' ' << (answer == INF ? -1 : answer) << '\n';
// //   }

// //   return 0;
// // }

// // void solve(int cur, int time, int prior) {
// //   // cout << "prior : " << prior << '\n';
// //   // cout << "cur : " << cur << ", time : " << time << '\n';

// //   if (time >= answer) return;
// //   if (prior == 2*N) {
// //     answer = time < answer ? time : answer;
// //     return;
// //   }

// //   int min_e = INF;
// //   for (int i = 0; i < 2 * N; ++i) {
// //     if (status[tasks[i].i]) continue;
// //     if (min_e < tasks[i].s) return;
// //     if (tasks[i].i >= N && !status[tasks[i].i - N]) return;
// //     if (time + get_abs(cur - tasks[i].p) > tasks[i].e) return;

// //     // cout << "task " << tasks[i].i << " >> p : " << tasks[i].p << ", s : " << tasks[i].s << ", e : " << tasks[i].e << '\n';
// //     status[tasks[i].i] = 1;
// //     solve(tasks[i].p, get_max(tasks[i].s, time + get_abs(cur - tasks[i].p)), prior + 1);
// //     status[tasks[i].i] = 0;

// //     if (min_e > tasks[i].e) min_e = tasks[i].e;
// //   }
// // }

// // int get_abs(int a) { return a < 0 ? -a : a; }
// // int get_min(int a, int b) { return a < b ? a : b; }
// // int get_max(int a, int b) { return a > b ? a : b; }

// // #include <iostream>
// // #include <algorithm>
// // #include <vector>
// // #define INF 987654321
// // using namespace std;

// // struct task {
// //   int p, s, e, i;
// // };

// // bool cmp(task a, task b) {
// //   if (a.s == b.s) return a.e < b.e;
// //   return a.s < b.s;
// // }

// // int T, N, R, P1, P2, T1, T2, answer;
// // vector<task> tasks;
// // vector<int> status;

// // int get_abs(int a);
// // int get_min(int a, int b);
// // int get_max(int a, int b);
// // void solve(int cur, int time, int prior);

// // int main(int argc, char *argv[]) {
// //   cin.tie(0);
// //   ios_base::sync_with_stdio(false);

// //   cin >> T;
// //   for (int test_case = 1; test_case <= T; ++test_case) {
// //     cin >> R >> N;
// //     answer = INF;
// //     tasks.resize(2 * N);
// //     status.clear();
// //     status.resize(2 * N, 0);
    
    
// //     int cur = R, time = 0;
// //     for (int i = 0; i < N; ++i) {
// //       cin >> P1 >> P2 >> T1 >> T2;
// //       tasks[i] = {P1, T1, T2 - get_abs(P2 - P1), i};
// //       tasks[i + N] = {P2, T1 + get_abs(P2 - P1), T2, i+N};
// //     }
// //     sort(tasks.begin(), tasks.end(), cmp);
// //     solve(cur, time, 0); 

// //     cout << '#' << test_case << ' ' << (answer == INF ? -1 : answer) << '\n';
// //   }

// //   return 0;
// // }

// // void solve(int cur, int time, int prior) {
// //   // cout << "prior : " << prior << '\n';
// //   // cout << "cur : " << cur << ", time : " << time << '\n';

// //   if (time >= answer) return;
// //   if (prior == 2*N) {
// //     answer = time < answer ? time : answer;
// //     return;
// //   }

// //   for (int i = 0; i < 2 * N; ++i) {
// //     if (!status[tasks[i].i] && time + get_abs(cur - tasks[i].p) > tasks[i].e) return;
// //   }

// //   int min_e = INF;
// //   for (int i = 0; i < 2 * N; ++i) {
// //     if (status[tasks[i].i]) continue;
// //     if (min_e < tasks[i].s) return;
// //     if (tasks[i].i >= N && !status[tasks[i].i - N]) return;
// //     // if (time + get_abs(cur - tasks[i].p) > tasks[i].e) return;

// //     // cout << "task " << tasks[i].i << " >> p : " << tasks[i].p << ", s : " << tasks[i].s << ", e : " << tasks[i].e << '\n';
// //     status[tasks[i].i] = 1;
// //     solve(tasks[i].p, get_max(tasks[i].s, time + get_abs(cur - tasks[i].p)), prior + 1);
// //     status[tasks[i].i] = 0;

// //     if (min_e > tasks[i].e) min_e = tasks[i].e;
// //   }
// // }

// // int get_abs(int a) { return a < 0 ? -a : a; }
// // int get_min(int a, int b) { return a < b ? a : b; }
// // int get_max(int a, int b) { return a > b ? a : b; }


// // #include <iostream>
// // #include <vector>
// // #define INF 987654321
// // using namespace std;

// // struct task {
// //   int src, dst, dept, arrv;
// // };

// // struct status {
// //   int stat, need;
// // };

// // int T, N, R, P1, P2, T1, T2, answer;
// // int get_abs(int a);
// // int get_min(int a, int b);
// // int get_max(int a, int b);
// // void solve(vector<task> tasks, vector<status> stats, int cur, int time, int prior);

// // int main(int argc, char *argv[]) {
// //   cin.tie(0);
// //   ios_base::sync_with_stdio(false);

// //   cin >> T;
// //   for (int test_case = 1; test_case <= T; ++test_case) {
// //     cin >> R >> N;
// //     answer = INF;
// //     vector<task> tasks(N);
// //     vector<status> stats(N);
    
// //     int cur = R, time = 0;
// //     for (int i = 0; i < N; ++i) {
// //       cin >> P1 >> P2 >> T1 >> T2;
// //       tasks[i] = {P1, P2, T1, T2};
// //       stats[i] = {0, get_max(T1, get_abs(P1 - R))};
// //     }

// //     solve(tasks, stats, cur, time, 0);

// //     cout << '#' << test_case << ' ' << (answer == INF ? -1 : answer) << '\n';
// //   }

// //   return 0;
// // }

// // void solve(vector<task> tasks, vector<status> stats, int cur, int time, int prior) {
// //   if (time >= answer) return;

// //   int min = INF;
// //   vector<int> min_idx;
// //   for (; prior < 2 * N; ++prior) {
// //     for (int i = 0; i < N; ++i) {
// //       if (!stats[i].stat) {
// //         stats[i].need = get_max(tasks[i].dept, time + get_abs(cur - tasks[i].src));
// //       } else if (stats[i].stat == 1) {
// //         stats[i].need = time + get_abs(cur - tasks[i].dst);
// //         if (stats[i].need > tasks[i].arrv) return;
// //       } else {
// //         stats[i].need = INF;
// //       }
// //     }

// //     min = INF;
// //     min_idx.clear();
// //     for (int i = 0; i < N; ++i) {
// //       if (stats[i].need < min) {
// //         min = stats[i].need;
// //         min_idx.clear();
// //         min_idx.push_back(i);
// //       } else if (stats[i].need == min) {
// //         min_idx.push_back(i);
// //       }
// //     }

// //     if (min == INF) return;

// //     if (min_idx.size() > 1) {
// //       time = min;
// //       int cur_tmp = cur;
// //       vector<int> stats_tmp(N);

// //       for (int j = 0; j < min_idx.size(); ++j) {
// //         cur = stats[min_idx[j]].stat ? tasks[min_idx[j]].dst : tasks[min_idx[j]].src;
// //         ++stats[min_idx[j]].stat;
// //         solve(tasks, stats, cur, time, prior + 1);
// //         --stats[min_idx[j]].stat;
// //         cur = cur_tmp;
// //       }
// //       return;
// //     } else {
// //       time = min;
// //       cur = stats[min_idx[0]].stat ? tasks[min_idx[0]].dst : tasks[min_idx[0]].src;
// //       ++stats[min_idx[0]].stat;
// //     }
// //   }

// //   if (prior == 2*N) {
// //     answer = time < answer ? time : answer;
// //     return;
// //   }
// // }

// // int get_abs(int a) { return a < 0 ? -a : a; }
// // int get_min(int a, int b) { return a < b ? a : b; }
// // int get_max(int a, int b) { return a > b ? a : b; }
