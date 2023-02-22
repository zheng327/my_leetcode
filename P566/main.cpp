/*
 * 566. ���ܾ���
 * �� MATLAB �У���һ���ǳ����õĺ��� reshape �������Խ�һ�� m x n ��������Ϊ��һ����С��ͬ��r x c�����¾��󣬵�������ԭʼ���ݡ�
 * ����һ���ɶ�ά���� mat ��ʾ�� m x n �����Լ����������� r �� c ���ֱ��ʾ��Ҫ���ع��ľ����������������
 * �ع���ľ�����Ҫ��ԭʼ���������Ԫ������ͬ�� �б���˳�� ��䡣
 * ������и��������� reshape �����ǿ����Һ���ģ�������µ����ܾ��󣻷������ԭʼ����
 *
 * ʾ�� 1��
 * ���룺mat = [[1,2],[3,4]], r = 1, c = 4
 * �����[[1,2,3,4]]
 *
 * ʾ�� 2��
 * ���룺mat = [[1,2],[3,4]], r = 2, c = 4
 * �����[[1,2],[3,4]]
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
