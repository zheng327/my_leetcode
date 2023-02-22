/*
 * 48. ��תͼ��
 * ����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�
 * ������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��
 *
 * ʾ�� 1��
 * ���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * �����[[7,4,1],[8,5,2],[9,6,3]]
 *
 * ʾ�� 2��
 * ���룺matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * �����[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < (n + 1) / 2; j++){
                //�ݴ��i�е�j�е�ֵ
                int temp = matrix[i][j];
                //�ı߸���һ��ֵ��ת90��
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix1 = {{1,2,3}, {4,5,6},{7,8,9}};
    vector<vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution solution;
    solution.rotate(matrix1);
    solution.rotate(matrix2);
    for(vector<int> i : matrix1){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(vector<int> i : matrix2){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
