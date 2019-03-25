#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;

set <pii> visited;
int A, B, C, D;

int main(int argc, char *argv[]) {
    scanf("%d %d %d %d", &A, &B, &C, &D);
    queue <piii> Q;
    Q.push({0, {0, 0}});
    visited.insert({0, 0});

    while (!Q.empty()) {
        int T = Q.front().X;
        int a = Q.front().Y.X;
        int b = Q.front().Y.Y;
        Q.pop();

        if (a == C && b == D) return !printf("%d\n", T);

        if (a != A && visited.find({A, b}) == visited.end()) {
            visited.insert({A, b});
            Q.push({T + 1, {A, b}});
        }
        if (b != B && visited.find({a, B}) == visited.end()) {
            visited.insert({a, B});
            Q.push({T + 1, {a, B}});
        }
        if (a != 0 && visited.find({0, b}) == visited.end()) {
            visited.insert({0, b});
            Q.push({T + 1, {0, b}});
        }
        if (b != 0 && visited.find({a, 0}) == visited.end()) {
            visited.insert({a, 0});
            Q.push({T + 1, {a, 0}});
        }
        if (a + b > A && visited.find({A, a + b - A}) == visited.end()) {
            visited.insert({A, a + b - A});
            Q.push({T + 1, {A, a + b - A}});
        } 
        if (a + b < A && visited.find({a + b, 0}) == visited.end()) {
            visited.insert({a + b, 0});
            Q.push({T + 1, {a + b, 0}});
        }
        if (a + b > B && visited.find({a + b - B, B}) == visited.end()) {
            visited.insert({a + b - B, B});
            Q.push({T + 1, {a + b - B, B}});
        }
        if (a + b < B && visited.find({0, a + b}) == visited.end()) {
            visited.insert({0, a + b});
            Q.push({T + 1, {0, a + b}});
        }
    }
 
    puts("-1"); 
    return 0;
}