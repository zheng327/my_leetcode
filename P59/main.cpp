/*
 * 59. 螺旋矩阵 II
 * 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 * 示例 1：
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 * 示例 2：
 * 输入：n = 1
 * 输出：[[1]]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int maxnum = n*n;
        int curnum = 1;
        int row = 0, col = 0;
        vector<vector<int>> dire = {{0,1},{1,0},{0,-1},{-1,0}};
        int dire_index = 0;
        vector<vector<int>> res(n, vector<int>(n));
        while(curnum <= maxnum){
            res[row][col] = curnum;
            curnum++;
            int nextrow = row + dire[dire_index][0];
            int nextcol = col + dire[dire_index][1];
            if(nextrow < 0 || nextrow >= n || nextcol < 0 || nextcol >= n || res[nextrow][nextcol] != 0){
                dire_index = (dire_index + 1) % 4;
                row += dire[dire_index][0];
                col += dire[dire_index][1];
            }
            else{
                row = nextrow;
                col = nextcol;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> res1,res2;
    Solution solution;
    res1 = solution.generateMatrix(3);
    res2 = solution.generateMatrix(1);
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
