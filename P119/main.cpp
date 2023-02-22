/*
 * 119. ������� II
 * ����һ���Ǹ����� rowIndex�����ء�������ǡ��ĵ� rowIndex �С�
 * �ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
 *
 * ʾ�� 1:
 * ����: rowIndex = 3
 * ���: [1,3,3,1]
 *
 * ʾ�� 2:
 * ����: rowIndex = 0
 * ���: [1]
 *
 * ʾ�� 3:
 * ����: rowIndex = 1
 * ���: [1,1]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev,curr;
        for(int i = 0; i <= rowIndex; ++i){
            curr.resize(i+1);
            curr[0] = 1;
            curr[i] = 1;
            for(int j = 1; j < i; ++j){
                curr[j] = prev[j-1] + prev[j];
            }
            prev = curr;
        }
        return prev;
    }
};

int main() {
    vector<int> result1, result2, result3;
    Solution solution;
    result1 = solution.getRow(3);
    result2 = solution.getRow(0);
    result3 = solution.getRow(1);
    for(int x:result1){
        cout << x << " ";
    }
    cout << endl;

    for(int x:result2){
        cout << x << " ";
    }
    cout << endl;

    for(int x:result3){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
