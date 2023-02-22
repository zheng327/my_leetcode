/*
 * 118. �������
 * ����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�
 * �ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
 *
 * ʾ�� 1:
 * ����: numRows = 5
 * ���: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 * ʾ�� 2:
 * ����: numRows = 1
 * ���: [[1]]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; ++i){
            res[i].resize(i+1);
            res[i][0] = 1;
            res[i][i] = 1;
            for(int j = 1; j < i; ++j){
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> result1, result2;
    result1 = solution.generate(5);
    result2 = solution.generate(1);
    for(vector<int> i:result1){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(vector<int> i:result2){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
