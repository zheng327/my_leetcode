/*
 * 290. 单词规律
 * 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
 *
 * 示例1:
 * 输入: pattern = "abba", s = "dog cat cat dog"
 * 输出: true
 *
 * 示例 2:
 * 输入:pattern = "abba", s = "dog cat cat fish"
 * 输出: false
 *
 * 示例 3:
 * 输入: pattern = "aaaa", s = "dog cat cat dog"
 * 输出: false
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> str2ch;
        unordered_map<char,string> ch2str;
        int m = s.length();
        int i = 0;
        for(char ch:pattern){
            if(i >= m){
                return false;
            }
            int j = i;
            while(j < m && s[j] != ' '){
                ++j;
            }
            string tmp = s.substr(i, j - i);
            if(str2ch.count(tmp) && str2ch[tmp] != ch){
                return false;
            }
            if(ch2str.count(ch) && ch2str[ch] != tmp){
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
};

int main() {
    string pattern1 = "abba", s1 = "dog cat cat dog";
    string pattern2 = "abba", s2 = "dog cat cat fish";
    string pattern3 = "aaaa", s3 = "dog cat cat dog";
    Solution solution;
    cout << solution.wordPattern(pattern1, s1) << endl;
    cout << solution.wordPattern(pattern2, s2) << endl;
    cout << solution.wordPattern(pattern3, s3) << endl;
    return 0;
}
