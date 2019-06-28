#include <cstdio>
char in[101], cmps[9] = "CHICKENS";
int main(int argc, char *argv[]) {
    scanf(" %s", in);
    for (int key = 0; key < 128; ++key) {
        bool flag = true;
        for (int i = 0; i < 8; ++i) 
            if ((in[i] ^ key) != cmps[i]) 
                flag = false;
        if (flag) {
            for (int i = 0; in[i]; ++i)
                in[i] ^= key;
            break;
        }
    }
    printf("%s\n", in);
    return 0;
}