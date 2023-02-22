/*
 * 242. 有效的字母异位词
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 *
 * 示例 1:
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 *
 * 示例 2:
 * 输入: s = "rat", t = "car"
 * 输出: false
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> counts_s,counts_t;
        for(char c:s){
            counts_s[c]++;
        }
        for(char c:t){
            counts_t[c]++;
        }
        if(counts_s == counts_t){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";
    Solution solution;
    cout << solution.isAnagram(s1, t1) << endl;
    cout << solution.isAnagram(s2, t2) << endl;
    return 0;
}
