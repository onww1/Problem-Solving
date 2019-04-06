#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char plane[6], cmd;
int booked, req;

int main(int argc, char *argv[]) {
  while (1) {
    scanf(" %s %d", plane, &booked);
    if (plane[0] == '#') break;
    while (1) {
      scanf(" %c %d", &cmd, &req);
      if (cmd == 'X') break;
      if (cmd == 'B' && booked + req <= 68) booked += req;
      if (cmd == 'C' && booked - req >= 0) booked -= req; 
    }
    printf("%s %d\n", plane, booked);
  }
  return 0;
}