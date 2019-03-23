/*
 *  BOJ 9536. 여우는 어떻게 울지?
 *
 *  시간 복잡도 : O(TN)
 *  공간 복잡도 : O(N)
 *
 *  text를 받아두고, 동물들의 울음을 받아서 각각 해싱을 한 다음 그 값을 set에 넣어둡니다.
 *  그리고 다시 text를 돌면서 한 단어별로 받아서 해싱을 해보고, set에 그 값이 있으면 무시하고,
 *  없다면 ans 배열에 넣어줍니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int T, L;
set <int> H;
char text[10500], ans[10500], in[110];

// 단어의 해시값을 구하는 함수
int get_hash(char *word) {
    int ret = 0;
    for (int i = 0; word[i]; ++i) 
        ret = (ret * 59 + word[i] - 'a') % 9999929;
    return ret;
}

// 단어의 해시값을 구하고, 그 값이 set에 있는지 확인한 뒤, 없다면 ans에 넣어주는 함수
void process(char *in, int &idx) {
    in[idx] = 0;
    int val = get_hash(in);
    if (H.find(val) == H.end()) {
        if (L) ans[L++] = ' ';
        for (int j = 0; in[j]; ++j) ans[L++] = in[j];
        ans[L] = 0;
    }
    idx = 0; in[0] = 0;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    getchar();

    while (T--) {
        H.clear(); 
        ans[0] = 0; L = 0;
        fgets(text, sizeof(text), stdin);   // text를 한 번에 받음.

        while (1) {
            scanf(" %s", in);
            if (!strcmp(in, "what")) {  // 첫 단어가 what이면 끝
                fgets(in, sizeof(in), stdin);
                break;
            }
            scanf(" %s", in); scanf(" %s", in);
            H.insert(get_hash(in)); // 울음소리의 해시값을 구해서 set에 넣어줌.
        }

        for (int i = 0, idx = 0; text[i]; ++i) {
            // 공백을 만나면 여태까지 저장한 단어를 가지고 처리
            if (text[i] == ' ' || text[i] == '\n') process(in, idx);
            // 문자면 문자를 단어에 추가하고, 만약 text의 끝이라면 여태 구한걸로 처리
            else {
                in[idx++] = text[i];
                if (!text[i + 1]) process(in, idx);
            }
        }

        // 정답을 출력
        printf("%s\n", ans);
    }
    return 0;
}