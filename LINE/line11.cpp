#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> ip;

bool valid(int num) {
    if( 0 <= num && num <= 255) return true;
    return false;
}

int atoi(string str) {
    int len = str.length();
    if(str.length() > 1 && str[0] == '0') return -1;
    int num = 0;
    for(int i=0; i<len; i++) {
        num = (num * 10) + str[i] - '0';
    }
    return num;
}

void dfs(string line, int t) {
    if( t == 4 ) {
        if( line.length() == 0){
            for(int i=0; i<3; i++){
               cout << ip[i] << '.';
            }
            cout << ip[3] << '\n';    
        }
        return;
    }
    
    int len = line.length();
    int prev = -1, cur = -1;
    for(int j=1; j<=3 && j<=len; j++) {
            cur = atoi(line.substr(0, j));
            if(prev == cur) continue;
            if(valid(cur)) {
                ip.push_back(cur);
                dfs(line.substr(j, len), t+1);
                ip.pop_back();
            }
            else continue;
            prev = cur;
    }
}

int main(int argc, const char *argv[]) {
    string line;
    getline(cin, line);
    
    dfs(line, 0);
    return 0;
}