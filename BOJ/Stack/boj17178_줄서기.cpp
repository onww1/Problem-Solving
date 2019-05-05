#include <cstdio>
#include <vector>
using namespace std;

int _stoi(char* str) {
    int ret = 0;
    for (int i = 0; str[i]; ++i) ret = ret * 10 + str[i] - '0';
    return ret;
}

struct person {
    char C;
    int N;

    bool operator< (const person &other) const {
        if (C == other.C) return N < other.N;
        return C < other.C;
    }
};

int N;
person P[500];
char ticket[6];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < 5 * N; ++i) {
        scanf(" %s", ticket);
        P[i].C = ticket[0];
        P[i].N = _stoi(ticket + 2);
    }    
    vector <int> st;

    person last = {'A', -1};
    for (int i = 0; i < 5 * N; ++i) {
        while (!st.empty() && P[st.back()] < P[i]) {
            if (P[st.back()] < last) return !printf("BAD\n");
            last = P[st.back()];
            st.pop_back(); 
        }
        if (P[i] < last) return !printf("BAD\n");
        if (i < 5 * N - 1 && P[i + 1] < P[i]) st.push_back(i);
        else last = P[i];
    }

    while (!st.empty()) {
        if (P[st.back()] < last) return !printf("BAD\n");
        last = P[st.back()];
        st.pop_back();
    }
    
    printf("GOOD\n");
    return 0;
}
