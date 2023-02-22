/*
 * 43. 字符串相乘
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 *
 * 示例 1:
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        //两个乘数中有一个为0，则乘积为0
        if(num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1+n2);
        //从两数的最低位开始相乘
        for(int i = n1 - 1; i >= 0; i--){
            for(int j = n2 - 1; j >= 0; j--){
                //第一个数的第i位与第二个数的第j位相乘，结果存到res的第i+j+1位
                res[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        //如果结果的第i位大于9则进位给第i-1位
        for(int i = n1 + n2 -1; i > 0; i--){
            res[i-1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
        string out;
        //确定起始位
        int index = res[0] == 0 ? 1 : 0;
        while(index < n1 + n2){
            //整型数组转换为字符串
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
