/*
 * 20. 有效的括号
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 * 示例 1：
 * 输入：s = "()"
 * 输出：true
 *
 * 示例 2：
 * 输入：s = "()[]{}"
 * 输出：true
 *
 * 示例 3：
 * 输入：s = "(]"
 * 输出：false
*/
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        //创建哈希表存放字符和它对应的编号
        unordered_map<char,int> m{{'(', 1}, {'{', 2}, {'[', 3},
                                  {')', 4}, {'}', 5}, {']', 6}};
        //创建一个栈，根据栈后进先出的特性判断括号是否有效
        stack<char> st;
        bool result = true;
        for(char c:s){
            int flag = m[c];
            //左括号入栈
            if(flag >= 1 && flag <= 3){
                st.push(c);
            }
            //右括号如果与栈顶的左括号匹配则将栈顶的左括号出栈
            else if(!st.empty() && flag == m[st.top()] + 3){
                st.pop();
            }
            //如果不匹配则括号无效，返回false
            else{
                result = false;
                break;
            }
        }
        //如果栈里还有未匹配的左括号存在，则返回false
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
