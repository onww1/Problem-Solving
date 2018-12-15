#include <cstdio>
#include <algorithm>
#include <cmath>

char buf[1<<17];
int idx = 1<<17;

inline char read()
{
    if (idx == 1<<17)
    {
        fread(buf, 1, 1<<17, stdin);
        idx = 0;
    }
    return buf[idx++];
}
inline int readInt()
{
    int sum = 0;
    char now = read();
    
    while (now == ' ' || now == '\n') now = read();
    while (now >= '0' && now <= '9')
    {
        sum = sum*10 + now-48;
        now = read();
    }
    
    return sum;
}

int main(int argc, char const *argv[])
{
    int length[5];
    for (int i=0; i<5; ++i) {
        length[i] = readInt();
    }

    std::sort(length, length+5);

    int cnt = 0;
    for (int i=0; i<3; ++i) {
        for (int j=i+1; j<4; ++j) {
            for (int k=j+1; k<5; ++k) {
                if (length[i] + length[j] > length[k]) cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}