/*
 * 566. 重塑矩阵
 * 在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
 * 给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
 * 重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
 * 如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
 *
 * 示例 1：
 * 输入：mat = [[1,2],[3,4]], r = 1, c = 4
 * 输出：[[1,2,3,4]]
 *
 * 示例 2：
 * 输入：mat = [[1,2],[3,4]], r = 2, c = 4
 * 输出：[[1,2],[3,4]]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(r*c != m*n){
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < m*n; i++){
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat1 = {{1,2},{3,4}};
    vector<vector<int>> mat2 = {{1,2},{3,4}};
    Solution solution;
    vector<vector<int>> res1 = solution.matrixReshape(mat1, 1, 4);
    vector<vector<int>> res2 = solution.matrixReshape(mat1, 2, 4);
    for(vector<int> i:res1){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(vector<int> i:res2){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
