/*
 * 73. 矩阵置零
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 *
 * 示例 1：
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 示例 2：
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m,0), col(n,0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix1 = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution solution;
    solution.setZeroes(matrix1);
    solution.setZeroes(matrix2);
    for(vector<int> i:matrix1){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(vector<int> i:matrix2){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
