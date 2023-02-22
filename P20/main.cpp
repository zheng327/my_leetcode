/*
 * 20. ��Ч������
 * ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
 * ��Ч�ַ��������㣺
 * �����ű�������ͬ���͵������űպϡ�
 * �����ű�������ȷ��˳��պϡ�
 * ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
 *
 * ʾ�� 1��
 * ���룺s = "()"
 * �����true
 *
 * ʾ�� 2��
 * ���룺s = "()[]{}"
 * �����true
 *
 * ʾ�� 3��
 * ���룺s = "(]"
 * �����false
*/
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        //������ϣ�����ַ�������Ӧ�ı��
        unordered_map<char,int> m{{'(', 1}, {'{', 2}, {'[', 3},
                                  {')', 4}, {'}', 5}, {']', 6}};
        //����һ��ջ������ջ����ȳ��������ж������Ƿ���Ч
        stack<char> st;
        bool result = true;
        for(char c:s){
            int flag = m[c];
            //��������ջ
            if(flag >= 1 && flag <= 3){
                st.push(c);
            }
            //�����������ջ����������ƥ����ջ���������ų�ջ
            else if(!st.empty() && flag == m[st.top()] + 3){
                st.pop();
            }
            //�����ƥ����������Ч������false
            else{
                result = false;
                break;
            }
        }
        //���ջ�ﻹ��δƥ��������Ŵ��ڣ��򷵻�false
        if(!st.empty())
            result = false;
        return result;
    }
};

int main() {
    string example1 = "()";
    string example2 = "()[]{}";
    string example3 = "(]";
    Solution solution;
    std::cout << solution.isValid(example1) << std::endl;
    std::cout << solution.isValid(example2) << std::endl;
    std::cout << solution.isValid(example3) << std::endl;
    return 0;
}
