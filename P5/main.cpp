/*
 * 5. 最长回文子串
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 * 示例 1：
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出："bb"
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int MaxLen = 1;
        int begin = 0;
        //长度为1的字符串，直接返回
        if(n <= 1)
            return s;
        //dp[i][j]表示，从字符串s的第i位到第j位的子串，是否是回文子串
        vector<vector<bool>> dp(n, vector<bool>(n));
        //每一位上的字符本身就是回文子串
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n; i++){
                int j = i + len - 1;
                //头尾的字符不相同，表示该子串不是回文子串
                if(s[i] != s[j])
                    dp[i][j] = false;
                else{
                    //如果头尾字符相同，且长度为2，则可以直接认为该子串是回文子串
                    if(len == 2)
                        dp[i][j] = true;
                    //长度大于2，则根据去头去尾的子串是否为回文串，来判断该子串是否为回文子串
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                //如果该子串为回文子串，且长度大于之前遍历的最长回文子串，则该子串为最长回文子串
                if(dp[i][j] == true && len > MaxLen){
                    MaxLen = len;
                    begin = i;
                }
            }
        }
        return s.substr(begin, MaxLen);
    }
};

int main() {
    string s1 = "babad", s2 = "cbbd";
    Solution solution;
    cout << solution.longestPalindrome(s1) << endl;
    cout << solution.longestPalindrome(s2) << endl;
    return 0;
}
