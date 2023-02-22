/*
 * 409. 最长回文串
 * 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 *
 * 示例 1:
 * 输入:s = "abccccdd"
 * 输出:7
 * 解释:我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 *
 * 示例 2:
 * 输入:s = "a"
 * 输入:1
 *
 * 示例 3：
 * 输入:s = "aaaaaccc"
 * 输入:7
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int sum = 0;
        for(char ch:s){
            if(++map[ch] == 2){
                sum += 2;
                map[ch] = 0;
            }
        }
        for(char ch = 'A'; ch <= 'z'; ch++){
            if(map[ch] == 1){
                return sum + 1;
            }
        }
        return sum;
    }
};
int main() {
    string s1 = "abccccdd";
    string s2 = "a";
    string s3 = "aaaaaccc";
    Solution solution;
    cout << solution.longestPalindrome(s1) << endl;
    cout << solution.longestPalindrome(s2) << endl;
    cout << solution.longestPalindrome(s3) << endl;
    return 0;
}
