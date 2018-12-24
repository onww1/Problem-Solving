#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum instruction {
  STA, LDA, BEQ, NOP, DEC, INC, JMP, HLT
};

int binaryToDec(string &binary, int start, int len);
int decode(string &memory);
int getX(string &memory);
void inc(string &val);
void dec(string &val);

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  vector<string> memory(32);
  string input;

  while (cin >> input) {
    int PC = 0;
    string val = "00000000";
    memory[0] = input;
    for (int i=1; i<32; ++i) {
      cin >> input;
      memory[i] = input;
    }

    bool loop = true;
    while (loop) {
      string &curMemory = memory[PC];
      PC = (PC + 1) % 32;
      int inst = decode(curMemory);
      switch (inst) {
        case STA:
          memory[getX(curMemory)] = val;
          break;
        case LDA:
          val = memory[getX(curMemory)];
          break;
        case BEQ:
          if (!binaryToDec(val, 0, 8))
            PC = getX(curMemory);
          break;
        case NOP:
          break;
        case DEC:
          dec(val);
          break;
        case INC:
          inc(val);
          break;
        case JMP:
          PC = getX(curMemory);
          break;
        case HLT:
          loop = false;
      }
    }

    cout << val << '\n';
  }
  return 0;
}

int binaryToDec(string &binary, int start, int len) {
  int res = 0;
  for (int i = start; i < start + len; ++i) {
    res *= 2;
    if (binary[i] == '1') res += 1;
  }
  return res;
}

int decode(string &memory) {
  return binaryToDec(memory, 0, 3);
}

int getX(string &memory) {
  return binaryToDec(memory, 3, 5);
}

void inc(string &val) {
  for (int i = 7; i >= 0; --i) {
    if (val[i] == '0') {
      ++val[i];
      break;
    } else {
      --val[i];
    }
  }
}

void dec(string &val) {
  for (int i = 7; i >= 0; --i) {
    if (val[i] == '1') {
      --val[i];
      break;
    } else {
      ++val[i];
    }
  }
}