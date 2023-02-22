/*
 * 415. �ַ������
 * ���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�
 * �㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
 *
 * ʾ�� 1��
 * ���룺num1 = "11", num2 = "123"
 * �����"134"
 *
 * ʾ�� 2��
 * ���룺num1 = "456", num2 = "77"
 * �����"533"
 *
 * ʾ�� 3��
 * ���룺num1 = "0", num2 = "0"
 * �����"0"
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int add = 0;
        string ans ="";
        while(i >= 0 || j >= 0 || add != 0){
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int sum = x + y + add;
            ans.push_back('0' + sum % 10);
            add = sum / 10;
            i -= 1;
            j -= 1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    string num1_1 = "11", num2_1 = "123";
    string num1_2 = "456", num2_2 = "77";
    string num1_3 = "0", num2_3 = "0";
    Solution solution;
    cout << num1_1 << " + " << num2_1 << " = " << solution.addStrings(num1_1, num2_1) << endl;
    cout << num1_2 << " + " << num2_2 << " = " << solution.addStrings(num1_2, num2_2) << endl;
    cout << num1_3 << " + " << num2_3 << " = " << solution.addStrings(num1_3, num2_3) << endl;
    return 0;
}
