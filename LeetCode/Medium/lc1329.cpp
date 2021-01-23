#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    public:
        void sortDiagonal(int start_r, int start_c, vector<vector<int>>& mat) {
            vector<int> v;
            int r = start_r, c = start_c;
            while (r < mat.size() && c < mat[0].size()) {
                v.push_back(mat[r][c]);
                r++, c++;
            }
            sort(v.begin(), v.end());
            r = start_r, c = start_c;
            for (int i = 0; i < v.size(); i++, r++, c++) 
                mat[r][c] = v[i];
        }

        vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
            int start_r = (int)mat.size() - 1, start_c = 0;
            while (start_r > 0) sortDiagonal(start_r--, start_c, mat);
            while (start_c < mat[0].size()) sortDiagonal(start_r, start_c++, mat);
            return mat;
        }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> mat = {
        {3, 3, 1, 1},
        {2, 2, 1, 2},
        {1, 1, 1, 2}
    };
    vector<vector<int>> ret = solution.diagonalSort(mat);
    vector<vector<int>> answer = {
        {1, 1, 1, 1},
        {1, 2, 2, 2},
        {1, 2, 3, 3}
    };
    assert(ret == answer);
    puts("PASS!");
    return 0;
}