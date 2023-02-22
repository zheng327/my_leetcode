/*
 * 43. �ַ������
 * �����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
 * ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������
 *
 * ʾ�� 1:
 * ����: num1 = "2", num2 = "3"
 * ���: "6"
 *
 * ʾ�� 2:
 * ����: num1 = "123", num2 = "456"
 * ���: "56088"
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        //������������һ��Ϊ0����˻�Ϊ0
        if(num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1+n2);
        //�����������λ��ʼ���
        for(int i = n1 - 1; i >= 0; i--){
            for(int j = n2 - 1; j >= 0; j--){
                //��һ�����ĵ�iλ��ڶ������ĵ�jλ��ˣ�����浽res�ĵ�i+j+1λ
                res[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        //�������ĵ�iλ����9���λ����i-1λ
        for(int i = n1 + n2 -1; i > 0; i--){
            res[i-1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
        string out;
        //ȷ����ʼλ
        int index = res[0] == 0 ? 1 : 0;
        while(index < n1 + n2){
            //��������ת��Ϊ�ַ���
            out.push_back(res[index] + '0');
            index++;
        }
        return out;
    }
};

int main() {
    string num1_1 = "2", num2_1 = "3";
    string num1_2 = "123", num2_2 = "456";
    Solution solution;
    cout << num1_1 << " * " << num2_1 << " = " << solution.multiply(num1_1, num2_1) << endl;
    cout << num1_2 << " * " << num2_2 << " = " << solution.multiply(num1_2, num2_2) << endl;
    return 0;
}
