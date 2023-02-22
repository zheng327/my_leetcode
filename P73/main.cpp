/*
 * 73. ��������
 * ����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
 *
 * ʾ�� 1��
 * ���룺matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * �����[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * ʾ�� 2��
 * ���룺matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * �����[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
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
