#include <cstdio>
int main(int argc, char *argv[]) {
  char team[2][11] = {"Persepolis", "Esteghlal"};
  int home[2], away[2];
  scanf("%d %d %d %d", &home[0], &away[1], &home[1], &away[0]);
  home[0] += away[0];
  home[1] += away[1];
  if (home[0] == home[1]) {
    if (away[0] == away[1]) return !printf("Penalty\n");
    else if (away[0] > away[1]) return !printf("%s\n", team[0]);
    else return !printf("%s\n", team[1]);
  } else if (home[0] > home[1]) return !printf("%s\n", team[0]);
  else return !printf("%s\n", team[1]);
}